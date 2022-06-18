#include <vector>
#include "IR.h"
#include "../models/Type.h"

using namespace std;

// CFG
CFG::CFG() {
    this->nextBBnumber = 0;
    this->nextFreeSymbolIndex = -4;
}

void CFG::add_bb(BasicBlock* bb) {
    this->bbs.push_back(bb);
}

void CFG::add_to_symbol_table (string name, Type *t) {
    this->SymbolType[name] = t;
    this->SymbolIndex[name] = this->nextFreeSymbolIndex;
    this->nextFreeSymbolIndex -= 4;
}

string CFG::create_new_tempvar(Type * t) {
    string name = "#temp" + to_string(this->nextFreeSymbolIndex);
    this->add_to_symbol_table(name, t);
    return name;
}

int CFG::get_var_index(string name) {
    return this->SymbolIndex[name];
}

Type* CFG::get_var_type(string name) {
    return this->SymbolType[name];
}

string CFG::new_BB_name() {
    return "BB" + to_string(this->nextBBnumber++);
}



// Basic block
void BasicBlock::add_IRInstr(IRInstr::Operation op, Type * t, vector<string> params) {
    instrs.push_back(new IRInstr(this, op, t, params));
}

BasicBlock::BasicBlock(CFG* cfg, string entry_label) {
    this->cfg = cfg;
    this->label = entry_label;
}

// IRInstr
IRInstr::IRInstr(BasicBlock* bb, Operation op, Type * t, vector<string> params) {
    this->bb = bb;
    this->op = op;
    this->t = t;
    this->params = params;
}

const IRInstr::Operation & IRInstr::getOp() const {
    return this->op;
}

const vector<string> & IRInstr::getParams() const {
    return this->params;
}