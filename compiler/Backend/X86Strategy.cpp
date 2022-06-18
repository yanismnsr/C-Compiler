#include <iostream>
#include "X86Strategy.h"

using namespace std;

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

void generateRetq(const IRInstr & instruction, ostream &o) {
    o << "  retq" << endl;
}

void generateReturn(const IRInstr & instruction, ostream &o) {
    vector<string> params = instruction.getParams();
    string mappedRegister = X86Strategy::registers[params[0]];
    
    o << "  movl    " << mappedRegister << ", %eax" << endl;
}

void X86Strategy::generate_assembly(const IRInstr & instruction, ostream &o) {
    // TODO Change the parameters of this method and implement it
    switch (instruction.getOp()) {
        case (IRInstr::Operation::pushq):
            generatePushq(instruction, o);
            break;
        default:
            cout << "Unsupported instruction";
    }
}