#pragma once

#include <iostream>
#include "BackendStrategy.h"

using namespace std;

class ARMStrategy : public BackendStrategy {

public:
    static map<string, string> registers;

    virtual void generate_assembly(const IRInstr & instruction, ostream &o);;

    virtual void generate_prologue(ostream &o);

    virtual void generate_epilogue(ostream &o, const CFG & cfg);

};