#pragma once

#include <iostream>
#include <map>
#include "BackendStrategy.h"
#include "../IR/IR.h"

using namespace std;

class X86Strategy : public BackendStrategy
{

public:
    static map<string, string> registers;

    virtual void generate_assembly(const IRInstr &instruction, ostream &o);

    virtual void generate_prologue(ostream &o);

    virtual void generate_epilogue(ostream &o, const CFG & cfg);
};

