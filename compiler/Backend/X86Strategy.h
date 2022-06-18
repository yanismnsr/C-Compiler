#pragma once

#include <iostream>
#include <map>
#include "BackendStrategy.h"
#include "../IR/IR.cpp"

using namespace std;

class X86Strategy : public BackendStrategy
{

public:
    static map<string, string> registers;

    virtual void generate_assembly(const IRInstr &instruction, ostream &o);
};

map<string, string> X86Strategy::registers = {
    {"%bp", "%rbp"},
    {"%sp", "%rsp"},
};