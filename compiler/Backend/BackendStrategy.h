#pragma once

#include <iostream>
#include "../IR/IR.h"

using namespace std;

class IRInstr;

class BackendStrategy {

    virtual void generate_assembly(const IRInstr & instruction, ostream &o) = 0;
    
};