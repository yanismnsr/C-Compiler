#pragma once

#include <iostream>
#include "../IR/IR.h"

using namespace std;

class IRInstr;
class CFG;
class BasicBlock;

class BackendStrategy {

public:
    virtual void generate_assembly(const IRInstr & instruction, ostream &o) = 0;

    virtual void generate_prologue(ostream &o) = 0;

    virtual void generate_epilogue(ostream &o, const CFG & cfg) = 0;

	virtual void generate_jump(const BasicBlock &basicBlock, ostream &o) = 0;
};