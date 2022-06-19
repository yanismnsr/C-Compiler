#include <iostream>
#include <regex>
#include "X86Strategy.h"
#include "../SymbolList.h"

using namespace std;

map<string, string> X86Strategy::registers = {
    {"%bp", "%rbp"},
    {"%sp", "%rsp"},
    {"%reg32", "%eax"},
    {"%reg64", "%rax"},
};

void generatePushq(const IRInstr & instruction, ostream &o) {
    vector<string> params = instruction.getParams();

    // This operation has only one parameter. Thus, the length of the 
    // parameters vector is 1.

    // Security check 
    if (params.size() != 1) {
        throw "Invalid number of parameters for the pushq instruction. Expected 1, got " + to_string(params.size());
    }

    string param = params[0];
    string mappedParameter = X86Strategy::registers[param];
    o << "  pushq   " << mappedParameter << endl;
}

void generatePopq(const IRInstr & instruction, ostream &o) {
    vector<string> params = instruction.getParams();

    // This operation has only one parameter. Thus, the length of the 
    // parameters vector is 1.

    // Security check 
    if (params.size() != 1) {
        throw "Invalid number of parameters for the popq instruction. Expected 1, got " + to_string(params.size());
    }

    string param = params[0];
    string mappedParameter = X86Strategy::registers[param];
    o << "  popq    " << mappedParameter << endl;
}

void generateRetq(const IRInstr & instruction, ostream &o) {
    o << "  retq" << endl;
}

void generateRet(const IRInstr & instruction, ostream &o) {
    o << "  ret" << endl;
}

void generateReturn(const IRInstr & instruction, ostream &o) {
    // Instruction with 1 parameter

    // Security check
    if (instruction.getParams().size() != 1) {
        throw "Invalid number of parameters for the return instruction. Expected 1, got " + to_string(instruction.getParams().size());
    }

    vector<string> params = instruction.getParams();

    SymbolList * symbols = SymbolList::getInstance();
    Symbol * symbol = symbols->getSymbol(params[0]);

    o << "  movl    " << symbol->memoryAddress << "(%rbp), %eax" << endl;
}

void generateDeclare(const IRInstr & instruction, ostream &o) {
    vector<string> params = instruction.getParams();
    string param = params[0];
    SymbolList * symbols = SymbolList::getInstance();
    symbols->addVariable(param);
}

void generateCopy(const IRInstr & instruction, ostream &o) {
    vector<string> params = instruction.getParams();
    string param1 = params[0];
    string param2 = params[1];

    // Symbol table
    SymbolList * symbols = SymbolList::getInstance();

    if (param1[0] == '%' && param2[0] != '%') { // param1 is a register
        // Mapping 
        string mappedParameter1 = X86Strategy::registers[param1];
        int parameter2Address = symbols->getSymbol(param2)->memoryAddress;
        o << "  movl    " << mappedParameter1 << ", " << parameter2Address << "(%rbp)" << endl;
    } else if (param2[0] == '%' && param1[0] != '%'){ // Parameter 2 is a register
        string mappedParameter2 = X86Strategy::registers[param2];
        int parameter1Address = symbols->getSymbol(param1)->memoryAddress;
        o << "  movl    " << parameter1Address << "(%rbp), " << mappedParameter2 << endl;
    } else {    // variable to variable
        int parameter1Address = symbols->getSymbol(param1)->memoryAddress;
        int parameter2Address = symbols->getSymbol(param2)->memoryAddress;
        o << "  movl    " << parameter1Address << "(%rbp), %eax" << endl;
        o << "  movl    %eax, " << parameter2Address << "(%rbp)" << endl;
    }
}

void generateLdconst (const IRInstr & instruction, ostream &o) {
    // ldconst const register
    // ldconst const variable
    vector<string> params = instruction.getParams();
    // parameters 
    string constValue = params[0];
    string destination = params[1];

    if (destination[0] == '%') {
        string mappedDestination = X86Strategy::registers[destination];
        o << "        movl    $" << constValue << ", " << mappedDestination << endl;
    } else {
        SymbolList * symbols = SymbolList::getInstance();
        int destinationAddress = symbols->getSymbol(destination)->memoryAddress;
        o << "        movl    $" << constValue << ", " << destinationAddress << "(%rbp)" << endl;
    } 
}


void generateWmem(const IRInstr & instruction, ostream &o) {
    vector<string> params = instruction.getParams();
    // Param1 : constant or register
    string param1 = params[0];

    // Param2 : variable
    string variable = params[1];
    SymbolList * symbols = SymbolList::getInstance();
    Symbol * symbol = symbols->getSymbol(variable);

    if (param1[0] == '%') { // param1 is a register
        // Mapping 
        string mappedParameter1 = X86Strategy::registers[param1];
        o << "  movl    " << mappedParameter1 << ", " << symbol->memoryAddress << "(%rbp)" << endl;
    } else { // param1 is a constant
        o << "  movl    $" << param1 << ", " << symbol->memoryAddress <<"(%rbp)" << endl;
    }
}

void generateRmem(const IRInstr & instruction, ostream &o) {
    vector<string> params = instruction.getParams();
    // Param1 : variable name
    string variable = params[0];
    SymbolList * symbols = SymbolList::getInstance();
    int variableOffset = symbols->getSymbol(variable)->memoryAddress;

    // Param2 : destination register
    string destination = params[1];
    string mappedDestination = X86Strategy::registers[destination];

    // Generate assembly
    o << "  movl    " << variableOffset << "(%rbp), " << mappedDestination << endl;
}

void generateAdd(const IRInstr & instruction, ostream &o) {
    // TODO check if negative constants work
    vector<string> params = instruction.getParams();

    // Param1 : Destination (register)
    string destination = params[0];
    string mappedDestination = X86Strategy::registers[destination];

    // Param2 : op1 (register, constant or variable)
    string operand1 = params[1];
    string param2 = "";
    if (regex_match(operand1, regex("-?[0-9]+"))) { // constant
        param2 = "&" + operand1;
    } else if (operand1[0] == '%') {                // register
        param2 = X86Strategy::registers[operand1];
    } else {                                        // variable
        SymbolList * symbols = SymbolList::getInstance();
        Symbol * symbol = symbols->getSymbol(operand1);
        param2 = to_string(symbol->memoryAddress) + "(%rbp)";
    }

    // Param3 : op2 (register, constant or variable)
    string operand2 = params[2];
    string param3 = "";
    if (regex_match(operand2, regex("-?[0-9]+"))) { // constant
        param3 = "&" + operand2;
    } else if (operand2[0] == '%') {                // register
        param3 = X86Strategy::registers[operand2];
    } else {                                        // variable
        SymbolList * symbols = SymbolList::getInstance();
        Symbol * symbol = symbols->getSymbol(operand2);
        param3 = to_string(symbol->memoryAddress) + "(%rbp)";
    }
}

void generateSub(const IRInstr & instruction, ostream &o) {
    // TODO implement this function
}

void generateMul(const IRInstr & instruction, ostream &o) {
    // TODO implement this function
}

void generateCall(const IRInstr & instruction, ostream &o) {
    // TODO implement this function
}

void generateCmpEq(const IRInstr & instruction, ostream &o) {
    // TODO implement this function
}

void generateCmpLt(const IRInstr & instruction, ostream &o) {
    // TODO implement this function
}

void generateCmpLe(const IRInstr & instruction, ostream &o) {
    // TODO implement this function
}

void generateReturnVar(const IRInstr & instruction, ostream &o) {
    // get param : variable name
    vector<string> params = instruction.getParams();
    string variable = params[0];

    // Symbol table
    SymbolList * symbols = SymbolList::getInstance();
    Symbol * symbol = symbols->getSymbol(variable);

    // Move symbol to %eax
    o << "        movl    " << symbol->memoryAddress << "(%rbp), %eax" << endl;
}

void X86Strategy::generate_assembly(const IRInstr & instruction, ostream &o) {

    // TODO Change the parameters of this method and implement it
    switch (instruction.getOp()) {
        case (IRInstr::Operation::pushq):
            generatePushq(instruction, o);
            break;
        case (IRInstr::Operation::popq):
            generatePopq(instruction, o);
            break;
        case (IRInstr::Operation::ldconst):
            generateLdconst(instruction, o);
            break;
        case (IRInstr::Operation::copy):
            generateCopy(instruction, o);
            break;
        case (IRInstr::Operation::add):
            generateAdd(instruction, o);
            break;
        case (IRInstr::Operation::sub):
            generateSub(instruction, o);
            break;
        case (IRInstr::Operation::mul):
            generateMul(instruction, o);
            break;
        case (IRInstr::Operation::rmem):
            generateRmem(instruction, o);
            break;
        case (IRInstr::Operation::wmem):
            generateWmem(instruction, o);
            break;
        case (IRInstr::Operation::call):
            generateCall(instruction, o);
            break;
        case (IRInstr::Operation::cmp_eq):
            generateCmpEq(instruction, o);
            break;
        case (IRInstr::Operation::cmp_lt):
            generateCmpLt(instruction, o);
            break;
        case (IRInstr::Operation::cmp_le):
            generateCmpLe(instruction, o);
            break;
        case (IRInstr::Operation::returnVar):
            generateReturnVar(instruction, o);
            break;
        case (IRInstr::Operation::declare):
            generateDeclare(instruction, o);
            break;
        case (IRInstr::Operation::ret):
            generateRet(instruction, o);
            break;
        case (IRInstr::Operation::retq):
            generateRetq(instruction, o);
            break;
        default:
            cerr << "Unsupported instruction";
    }
}

void X86Strategy::generate_prologue(ostream &o) {    
    // detect and adapt for MAC_OS specificity
	string main = "main";

	#ifdef __APPLE__
		main = "_main";
	#endif

    o << ".globl	" << main << "\n"
		 << main << ": \n"
        "	pushq	%rbp\n"
        "	movq	%rsp, %rbp\n";

}

void X86Strategy::generate_epilogue(ostream &o, const CFG & cfg) {
    cout << "	movq	%rbp, %rsp\n"
         << "	popq	%rbp\n";

    if (cfg.isReturnStatementPresent()) {
        cout << "	ret\n";
    } else {
        cout << "	retq\n";
    }

    SymbolList * symbols = SymbolList::getInstance();
    symbols->checkAreAllDeclaredVariablesUsedAndInitialized();
	if (symbols->getHasError()) 
	{
		throw std::runtime_error("");
	}
}