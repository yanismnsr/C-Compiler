#pragma once

#include <iostream>
#include "BackendStrategy.h"

using namespace std;

class ARMStrategy : public BackendStrategy {

    virtual void generate_assembly(const IRInstr & instruction, ostream &o);;

};