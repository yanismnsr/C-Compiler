#include <vector>
#include "IR.h"
#include "../models/Type.h"

using namespace std;

// CFG
CFG::CFG() {
    this->nextBBnumber = 0;
    this->nextFreeSymbolIndex = -4;
}

CFG::CFG(BackendStrategy * backendStrategy) {
    this->nextBBnumber = 0;
    this->nextFreeSymbolIndex = -4;
    this->backend = backendStrategy;
}

void CFG::add_bb(BasicBlock* bb) {
    this->bbs.push_back(bb);
    this->current_bb = bb;
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

void CFG::gen_asm(ostream& o) const {
    this->gen_asm_prologue(o);
    for (BasicBlock* bb : this->bbs) {
        bb->gen_asm(o, this->backend);
    }
    this->gen_asm_epilogue(o);
}

void CFG::gen_asm_prologue(ostream& o) const {
    this->backend->generate_prologue(o);
}

void CFG::gen_asm_epilogue(ostream& o) const {
    this->backend->generate_epilogue(o, *this);
}

void CFG::setReturnInstructionPresent() {
    this->hasReturnStatement = true;
}

bool CFG::isReturnStatementPresent() const {
    return this->hasReturnStatement;
}

void CFG::errorFound() {
    this->hasError = true; 
}


bool CFG::getHasError() const {
    return this->hasError; 
}


// Basic block
BasicBlock::BasicBlock(CFG* cfg, string entry_label) {
    this->cfg = cfg;
    this->label = entry_label;
    this->symbolTable = new SymbolTable(this);
}

BasicBlock::BasicBlock(CFG* cfg, string entry_label, const BasicBlock & parentBasicBlock) {
    this->cfg = cfg;
    this->label = entry_label;
    this->symbolTable = new SymbolTable(this, parentBasicBlock.symbolTable);
}

void BasicBlock::add_IRInstr(IRInstr::Operation op, Type * t, vector<string> params) {
    instrs.push_back(new IRInstr(this, op, t, params));
}

void BasicBlock::gen_asm(ostream &o, BackendStrategy *backend) {
    for (IRInstr* instr : this->instrs) {
        instr->gen_asm(o, backend);
    }
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

void IRInstr::gen_asm(ostream &o, BackendStrategy* backend) {
    backend->generate_assembly(*this, o);
}

BasicBlock * IRInstr::getContainingBasicBlock() const {
    return this->bb;
}

SymbolTable * IRInstr::getSymbolTable() const {
    return this->bb->symbolTable;
}