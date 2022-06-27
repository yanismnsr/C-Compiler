#pragma once

#include <iostream>
#include "BackendStrategy.h"

using namespace std;

class ARMStrategy : public BackendStrategy {

public:
    static map<string, string> registers;

    virtual void generate_assembly(const IRInstr & instruction, ostream &o);;

    virtual void generate_prologue(ostream &o, const CFG & cfg);

    virtual void generate_epilogue(ostream &o, const CFG & cfg);

	virtual void generate_jump(const BasicBlock &basicBlock, ostream &o);

};