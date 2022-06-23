#include <iostream>
#include <regex>
#include "X86Strategy.h"
#include "../SymbolTable.h"

using namespace std;

map<string, string> X86Strategy::registers = {
    {"%bp", "%rbp"},
    {"%sp", "%rsp"},
    {"%reg32", "%eax"},
    {"%reg64", "%rax"},
};

void generatePushq(const IRInstr &instruction, ostream &o)
{
    vector<string> params = instruction.getParams();

    // This operation has only one parameter. Thus, the length of the
    // parameters vector is 1.

    // Security check
    if (params.size() != 1)
    {
        throw "Invalid number of parameters for the pushq instruction. Expected 1, got " + to_string(params.size());
    }

    string param = params[0];
    string mappedParameter = X86Strategy::registers[param];
    o << "  pushq   " << mappedParameter << endl;
}

void generatePopq(const IRInstr &instruction, ostream &o)
{
    vector<string> params = instruction.getParams();

    // This operation has only one parameter. Thus, the length of the
    // parameters vector is 1.

    // Security check
    if (params.size() != 1)
    {
        throw "Invalid number of parameters for the popq instruction. Expected 1, got " + to_string(params.size());
    }

    string param = params[0];
    string mappedParameter = X86Strategy::registers[param];
    o << "  popq    " << mappedParameter << endl;
}

void generateRetq(const IRInstr &instruction, ostream &o)
{
    o << "  retq" << endl;
}

void generateRet(const IRInstr &instruction, ostream &o)
{
    o << "  ret" << endl;
}

void generateReturn(const IRInstr &instruction, ostream &o)
{
    // Instruction with 1 parameter

    SymbolTable * symbolTable = instruction.getSymbolTable();

    // Security check
    if (instruction.getParams().size() != 1)
    {
        throw "Invalid number of parameters for the return instruction. Expected 1, got " + to_string(instruction.getParams().size());
    }

    vector<string> params = instruction.getParams();

    Symbol *symbol = symbolTable->getSymbol(params[0]);

    o << "  movl    " << symbol->memoryAddress << "(%rbp), %eax" << endl;
}

void generateDeclare(const IRInstr &instruction, ostream &o)
{
    SymbolTable * symbolTable = instruction.getSymbolTable();

    vector<string> params = instruction.getParams();
    string param = params[0];
    symbolTable->addVariable(param);
}

void generateCopy(const IRInstr &instruction, ostream &o)
{
    vector<string> params = instruction.getParams();
    string param1 = params[0];
    string param2 = params[1];

    // Symbol table
    SymbolTable * symbolTable = instruction.getSymbolTable();

    if (param1[0] == '%' && param2[0] != '%')
    { // param1 is a register
        // Mapping
        string mappedParameter1 = X86Strategy::registers[param1];
        int parameter2Address = symbolTable->getSymbol(param2)->memoryAddress;
        o << "  movl    " << mappedParameter1 << ", " << parameter2Address << "(%rbp)" << endl;
    }
    else if (param2[0] == '%' && param1[0] != '%')
    { // Parameter 2 is a register
        string mappedParameter2 = X86Strategy::registers[param2];
        int parameter1Address = symbolTable->getSymbol(param1)->memoryAddress;
        o << "  movl    " << parameter1Address << "(%rbp), " << mappedParameter2 << endl;
    }
    else
    { // variable to variable
        int parameter1Address = symbolTable->getSymbol(param1)->memoryAddress;
        int parameter2Address = symbolTable->getSymbol(param2)->memoryAddress;
        o << "  movl    " << parameter1Address << "(%rbp), %eax" << endl;
        o << "  movl    %eax, " << parameter2Address << "(%rbp)" << endl;
    }
}

void generateLdconst(const IRInstr &instruction, ostream &o)
{
    // ldconst const register
    // ldconst const variable
    vector<string> params = instruction.getParams();
    // parameters
    string constValue = params[0];
    string destination = params[1];

    if (destination[0] == '%')
    {
        string mappedDestination = X86Strategy::registers[destination];
        o << "        movl    $" << constValue << ", " << mappedDestination << endl;
    }
    else
    {
        SymbolTable * symbolTable = instruction.getSymbolTable();
        int destinationAddress = symbolTable->getSymbol(destination)->memoryAddress;
        o << "        movl    $" << constValue << ", " << destinationAddress << "(%rbp)" << endl;
    }
}

void generateWmem(const IRInstr &instruction, ostream &o)
{
    vector<string> params = instruction.getParams();
    // Param1 : constant or register
    string param1 = params[0];

    // Param2 : variable
    string variable = params[1];

    SymbolTable * symbolTable = instruction.getSymbolTable();

    Symbol *symbol = symbolTable->getSymbol(variable);

    if (param1[0] == '%')
    { // param1 is a register
        // Mapping
        string mappedParameter1 = X86Strategy::registers[param1];
        o << "  movl    " << mappedParameter1 << ", " << symbol->memoryAddress << "(%rbp)" << endl;
    }
    else
    { // param1 is a constant
        o << "  movl    $" << param1 << ", " << symbol->memoryAddress << "(%rbp)" << endl;
    }
}

void generateRmem(const IRInstr &instruction, ostream &o)
{

    SymbolTable * symbolTable = instruction.getSymbolTable();

    vector<string> params = instruction.getParams();
    // Param1 : variable name
    string variable = params[0];

    int variableOffset = symbolTable->getSymbol(variable)->memoryAddress;

    // Param2 : destination register
    string destination = params[1];
    string mappedDestination = X86Strategy::registers[destination];

    // Generate assembly
    o << "  movl    " << variableOffset << "(%rbp), " << mappedDestination << endl;
}

void generateAdd(const IRInstr &instruction, ostream &o)
{
    // TODO check if negative constants work
    vector<string> params = instruction.getParams();

    // Param1 : Destination (register)
    string destination = params[0];
    string mappedDestination = X86Strategy::registers[destination];

    // Param2 : op1 (register, constant or variable)
    string operand1 = params[1];
    if (regex_match(operand1, regex("-?[0-9]+")))
    { // constant
        o << "  movl    $" << operand1 << ", %eax" << endl;
    }
    else if (operand1[0] == '%')
    { // register
        string mappedRegister = X86Strategy::registers[operand1];
        o << "  movl    " << mappedRegister << ", %eax" << endl;
    }
    else
    { // variable

        SymbolTable * symbolTable = instruction.getSymbolTable();

        Symbol *symbol = symbolTable->getSymbol(operand1);
        if (symbol != nullptr)
        {
            int variableOffset = symbol->memoryAddress;
            o << "  movl    " << variableOffset << "(%rbp), %eax" << endl;
        }
    }

    // Param3 : op2 (register, constant or variable)
    string operand2 = params[2];
    if (regex_match(operand2, regex("-?[0-9]+")))
    { // constant
        o << "  addl    $" << operand2 << ", %eax" << endl;
    }
    else if (operand2[0] == '%')
    { // register
        string mappedRegister = X86Strategy::registers[operand2];
        o << "  addl    " << mappedRegister << ", %eax" << endl;
    }
    else
    { // variable

        SymbolTable * symbolTable = instruction.getSymbolTable();

        Symbol *symbol = symbolTable->getSymbol(operand2);
        if (symbol != nullptr)
        {
            int variableOffset = symbol->memoryAddress;
            o << "  addl    " << variableOffset << "(%rbp), %eax" << endl;
        }
    }

    // Destination
    if (destination[0] == '%')
    { // register
        o << "  movl    %eax, " << mappedDestination << endl;
    }
    else
    { // variable

        SymbolTable * symbolTable = instruction.getSymbolTable();

        Symbol *symbol = symbolTable->getSymbol(destination);
        if (symbol != nullptr)
        {
            int variableOffset = symbol->memoryAddress;
            o << "  movl    %eax, " << variableOffset << "(%rbp)" << endl;
        }
    }
}

void generateSub(const IRInstr &instruction, ostream &o)
{
    // TODO implement this function
    vector<string> params = instruction.getParams();

    // Param1 : Destination (register)
    string destination = params[0];
    string mappedDestination = X86Strategy::registers[destination];

    // Param2 : op1 (register, constant or variable)
    string operand1 = params[1];
    if (regex_match(operand1, regex("-?[0-9]+"))){ // constant
        o << "  movl    $" << operand1 << ", %eax" << endl;
    }
    else if (operand1[0] == '%'){ // register
        string mappedRegister = X86Strategy::registers[operand1];
        o << "  movl    " << mappedRegister << ", %eax" << endl;
    }
    else{ // variable

        SymbolTable * symbolTable = instruction.getSymbolTable();

        Symbol *symbol = symbolTable->getSymbol(operand1);
        if (symbol != nullptr)
        {
            int variableOffset = symbol->memoryAddress;
            o << "  movl    " << variableOffset << "(%rbp), %eax" << endl;
        }
    }

    // Param3 : op2 (register, constant or variable)
    string operand2 = params[2];
    if (regex_match(operand2, regex("-?[0-9]+"))){ // constant
        o << "  subl    $" << operand2 << ", %eax" << endl;
    }
    else if (operand2[0] == '%'){ // register
        string mappedRegister = X86Strategy::registers[operand2];
        o << "  subl    " << mappedRegister << ", %eax" << endl;
    }
    else{ // variable
        
        SymbolTable * symbolTable = instruction.getSymbolTable();

        Symbol *symbol = symbolTable->getSymbol(operand2);
        if (symbol != nullptr){
            int variableOffset = symbol->memoryAddress;
            o << "  subl    " << variableOffset << "(%rbp), %eax" << endl;
        }
    }

    // Destination
    if (destination[0] == '%'){ // register
        o << "  movl    %eax, " << mappedDestination << endl;
    }
    else{ // variable
        SymbolTable * symbolTable = instruction.getSymbolTable();
        Symbol *symbol = symbolTable->getSymbol(destination);
        if (symbol != nullptr){
            int variableOffset = symbol->memoryAddress;
            o << "  movl    %eax, " << variableOffset << "(%rbp)" << endl;
        }
    }
}

void generateMul(const IRInstr &instruction, ostream &o)
{
    // Operand 1 : Destination
    // Operand 2 : OP1
    // Operand 3 : OP2
    // Destination = OP1 * OP2

    vector<string> params = instruction.getParams();

    // Param1 : Destination
    string destination = params[0];

    // Param2 : op1 (register, constant or variable)
    string operand1 = params[1];
    if (regex_match(operand1, regex("-?[0-9]+"))){ // constant
        o << "  movl    $" << operand1 << ", %eax" << endl;
    }
    else if (operand1[0] == '%'){ // register
        string mappedRegister = X86Strategy::registers[operand1];
        o << "  movl    " << mappedRegister << ", %eax" << endl;
    }
    else{ // variable
        SymbolTable * symbolTable = instruction.getSymbolTable();
        Symbol *symbol = symbolTable->getSymbol(operand1);
        if (symbol != nullptr){
            int variableOffset = symbol->memoryAddress;
            o << "  movl    " << variableOffset << "(%rbp), %eax" << endl;
        }
    }

    // Param3 : op2 (register, constant or variable)
    string operand2 = params[2];
    if (regex_match(operand2, regex("-?[0-9]+"))){ // constant
        cerr << operand2 << " debug mode " << endl;
        o << "  imull    $" << operand2 << ", %eax #const " << endl;
    }
    else if (operand2[0] == '%'){ // register
        string mappedRegister = X86Strategy::registers[operand2];
        o << "  imull    " << mappedRegister << ", %eax #register " << endl;
    }
    else{ // variable
        SymbolTable * symbolTable = instruction.getSymbolTable();
        Symbol *symbol = symbolTable->getSymbol(operand2);
        if (symbol != nullptr){
            int variableOffset = symbol->memoryAddress;
            o << "  imull    " << variableOffset << "(%rbp), %eax   #variable  " << endl;
        }
    }

    // Destination
    if (destination[0] == '%'){ // register
        string mappedDestination = X86Strategy::registers[destination];
        o << "  movl    %eax, " << mappedDestination << endl;
    }
    else{ // variable
        SymbolTable * symbolTable = instruction.getSymbolTable();
        Symbol *symbol = symbolTable->getSymbol(destination);
        if (symbol != nullptr){
            int variableOffset = symbol->memoryAddress;
            o << "  movl    %eax, " << variableOffset << "(%rbp)" << endl;
        }
    }
}

void generateDiv(const IRInstr &instruction, ostream &o)
{
    vector<string> params = instruction.getParams();

    // Param1 : Destination (register)
    string destination = params[0];
    string mappedDestination = X86Strategy::registers[destination];

    // Param2 : op1 (register, constant or variable)
    string operand1 = params[1];
    if (regex_match(operand1, regex("-?[0-9]+")))
    { // constant
        o << "  movl    $" << operand1 << ", %eax" << endl;
    }
    else if (operand1[0] == '%')
    { // register
        string mappedRegister = X86Strategy::registers[operand1];
        o << "  movl    " << mappedRegister << ", %eax" << endl;
    }
    else
    { // variable
        SymbolTable * symbolTable = instruction.getSymbolTable();
        Symbol *symbol = symbolTable->getSymbol(operand1);
        if (symbol != nullptr)
        {
            int variableOffset = symbol->memoryAddress;
            o << "  movl    " << variableOffset << "(%rbp), %eax" << endl;
        }
    }

    o << "cltd    # initialize sign register" << endl;

    // Param3 : op2 (register, constant or variable)
    string operand2 = params[2];
    if (regex_match(operand2, regex("-?[0-9]+")))
    { // constant
        cerr << operand2 << " debug mode " << endl;
        o << "  idivl    $" << operand2 << " #const " << endl;
    }
    else if (operand2[0] == '%')
    { // register
        string mappedRegister = X86Strategy::registers[operand2];
        o << "  idivl    " << mappedRegister << " #register " << endl;
    }
    else
    { // variable
        SymbolTable * symbolTable = instruction.getSymbolTable();
        Symbol *symbol = symbolTable->getSymbol(operand2);
        if (symbol != nullptr)
        {
            int variableOffset = symbol->memoryAddress;
            o << "  idivl    " << variableOffset << "(%rbp)   #variable  " << endl;
        }
    }

    // Destination
    if (destination[0] == '%')
    { // register
        o << "  movl    %eax, " << mappedDestination << endl;
    }
    else
    { // variable
        SymbolTable * symbolTable = instruction.getSymbolTable();
        Symbol *symbol = symbolTable->getSymbol(destination);
        if (symbol != nullptr)
        {
            int variableOffset = symbol->memoryAddress;
            o << "  movl    %eax, " << variableOffset << "(%rbp)" << endl;
        }
    }
}

void generateCall(const IRInstr &instruction, ostream &o)
{
    // TODO implement this function
}

void generateCmpEq(const IRInstr &instruction, ostream &o)
{
    // TODO implement this function
}

void generateCmpLt(const IRInstr &instruction, ostream &o)
{
    // TODO implement this function
}

void generateCmpLe(const IRInstr &instruction, ostream &o)
{
    // TODO implement this function
}

void generateReturnVar(const IRInstr &instruction, ostream &o)
{
    // get param : variable name
    vector<string> params = instruction.getParams();
    string variable = params[0];

    // Symbol table
    SymbolTable * symbolTable = instruction.getSymbolTable();
    Symbol *symbol = symbolTable->getSymbol(variable);

    // Move symbol to %eax
    o << "        movl    " << symbol->memoryAddress << "(%rbp), %eax" << endl;
}

void X86Strategy::generate_assembly(const IRInstr &instruction, ostream &o)
{

    // TODO Change the parameters of this method and implement it
    switch (instruction.getOp())
    {
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
    case (IRInstr::Operation::div):
        generateDiv(instruction, o);
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

void X86Strategy::generate_prologue(ostream &o)
{
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

void X86Strategy::generate_epilogue(ostream &o, const CFG &cfg)
{
    cout << "	movq	%rbp, %rsp\n"
         << "	popq	%rbp\n";

    if (cfg.isReturnStatementPresent())
    {
        cout << "	ret\n";
    }
    else
    {
        cout << "	retq\n";
    }

    SymbolTable * symbolTable = cfg.current_bb->symbolTable;
    symbolTable->checkAreAllDeclaredVariablesUsedAndInitialized();
    if (cfg.getHasError())
    {
        throw std::runtime_error("");
    }
}
