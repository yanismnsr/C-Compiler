#include <vector>
#include "IR.h"
#include "../models/Type.h"

using namespace std;

// CFG
CFG::CFG() {
    this->nextBBnumber = 0;
    this->nextFreeSymbolIndex = -4;
    this->current_bb = nullptr;
}

CFG::CFG(BackendStrategy * backendStrategy, string functionName) {
    this->nextBBnumber = 0;
    this->nextFreeSymbolIndex = -4;
    this->backend = backendStrategy;
    this->functionName = functionName;
    this->current_bb = nullptr;
}

void CFG::add_bb(BasicBlock* bb) {
    this->bbs.push_back(bb);
    if (this->current_bb != nullptr && !this->previousBlockIsReturnBlock) {
        bb->exit_true = this->current_bb->exit_true;
        this->current_bb->exit_true = bb;
    } 
    this->current_bb = bb;

    // for (BasicBlock * bb : bb->cfg->bbs) {
    //     if (bb->exit_true) {
    //         cout << bb->label << " >> " << bb->exit_true->label << " :: ";
    //     } 
    //     if (bb->exit_false) {
    //         cout << bb->label << " >>> " << bb->exit_false->label << " :: ";
    //     } 
    //     if (!bb->exit_true && !bb->exit_false) {
    //         cout << "NA: " << bb->label << " :: ";
    //     }
    // }
    // cout << endl;
    
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
}

void CFG::gen_asm_prologue(ostream& o) const {
    this->backend->generate_prologue(o, *this);
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

string CFG::getFunctionName() const {
    return this->functionName;
}

void CFG::add_exit_falseBB(BasicBlock * ifBb, BasicBlock * newBb, BasicBlock * defaultBb) {
    this->bbs.push_back(newBb);
    ifBb->exit_false = newBb;
    newBb->exit_true = defaultBb;
    this->current_bb = newBb;

    // for (BasicBlock * bb : ifBb->cfg->bbs) {
    //     if (bb->exit_true) {
    //         cout << bb->label << " >> " << bb->exit_true->label << " :: ";
    //     } 
    //     if (bb->exit_false) {
    //         cout << bb->label << " >>> " << bb->exit_false->label << " :: ";
    //     } 
    //     if (!bb->exit_true && !bb->exit_false) {
    //         cout << "NA: " << bb->label << " :: ";
    //     }
    // }
    // cout << endl;
}

void CFG::add_exit_falseBB(BasicBlock * ifBb, BasicBlock * newBb) {
    this->bbs.push_back(newBb);
    ifBb->exit_false = newBb;
    this->current_bb = newBb;

    // for (BasicBlock * bb : ifBb->cfg->bbs) {
    //     if (bb->exit_true) {
    //         cout << bb->label << " >> " << bb->exit_true->label << " :: ";
    //     } 
    //     if (bb->exit_false) {
    //         cout << bb->label << " >>> " << bb->exit_false->label << " :: ";
    //     } 
    //     if (!bb->exit_true && !bb->exit_false) {
    //         cout << "NA: " << bb->label << " :: ";
    //     }
    // }
    // cout << endl;
}


// Basic block
BasicBlock::BasicBlock(CFG* cfg, string entry_label) {
    this->cfg = cfg;
    this->label = entry_label;
    this->symbolTable = new SymbolTable(this);
    this->exit_true = nullptr;
    this->exit_false = nullptr;
    this->parentBb = nullptr;
}

BasicBlock::BasicBlock(CFG* cfg, string entry_label, BasicBlock & parentBasicBlock) {
    this->cfg = cfg;
    this->label = entry_label;
    this->symbolTable = new SymbolTable(this, parentBasicBlock.symbolTable);
    this->exit_true = nullptr;
    this->exit_false = nullptr;
    this->parentBb = &parentBasicBlock;
}

void BasicBlock::add_IRInstr(IRInstr::Operation op, Type * t, vector<string> params) {
    instrs.push_back(new IRInstr(this, op, t, params));
}

void BasicBlock::gen_asm(ostream &o, BackendStrategy *backend) {
    if (this->label != "prologue") {
        o << this->label << ":" << endl;
    }
    for (IRInstr* instr : this->instrs) {
        instr->gen_asm(o, backend);
    }
    
    backend->generate_jump(*this, o);
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