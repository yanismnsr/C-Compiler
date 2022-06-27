#pragma once

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <initializer_list>
#include "../Backend/BackendStrategy.h"
#include "../models/Type.h"
#include "../SymbolTable.h"

class BasicBlock;
class CFG;
class BackendStrategy;
class SymbolTable;


using namespace std;

/*
Exemple de IR.h trouvé sur moodle (peut-être qu'il faut le ranger ailleurs)
*/


/**
 * @brief The parameters are organized as follow :
 * 	The first thing to consider is that when a parameter is a register,
 * 	it always begins with the '%' character. To test if a parameter is a
 * 	register, you can thus use the (param[0] == '%') test.
 *
 * 	Second, the name of registers in the Intermediate Representation (IR) are
 * 	generic names (non specific to the architecture). A mapper to every specific
 * 	architecture have to be implemented when implementing the backend that
 * 	generated the assembly (BackendStrategy). See the X86Strategy for an example.
 *
 * ## 1 parameter operations
 * 	### (pushq, popq)
 * 		The parameter vector is of size one. It contains the only operand. As the
 * 		operands are always registers, they begin with the '%' character. Therefore,
 * 		they should be mapped to the specific registers of the architecture.
 * 	### (declare, returnVar)
 * 		The parameter vector is of size one. It contains the only operand. They are
 * 		variable names for those operations. You have to get their address using
 * 		the symbol table.
 *
 *
 * ## 2 parameters operations (copy, ldconst)
 * 		Operand one : Source
 * 		Operand two : Destination
 * 	### ldconst
 * 		* ldconst const register
 * 		* ldconst const variable
 *  ### copy
 * 		* copy register memoryOffset
 * 		* copy memoryOffset register
 * 	### rmem
 * 		* rmem variableName register
 * 	### wmem
 * 		* wmem register variableName
 * 		* wmem constant variableName
 *
 * ## 3 parameters operations
 * 	### add, sub, mul, div, cmp_e, cmp_ne, cmp_gt, cmp_ge, cmp_lt, cmp_le, andop, orop
 * 		Operand one : Destination
 * 		Operand two : op1 (register, constant or variable)
 * 		Operand three : op2 (register, constant or variable)
 *
 */


//! The class for one 3-address instruction
class IRInstr {

   public:
	/** The instructions themselves -- feel free to subclass instead */
	typedef enum {
		ldconst,
		copy,
		add,
		sub,
		mul,
		div,
		rmem,
		wmem,
		pushq,
		popq,
		call,
		cmp_eq,
		cmp_ne,
		cmp_gt,
		cmp_ge,
		cmp_lt,
		cmp_le,
		returnVar,
		declare,
		ret,
		retq,
		andop,
		orop,
		new_function
	} Operation;


	/**  constructor */
	IRInstr(BasicBlock* bb_, Operation op, Type *t, vector<string> params);

	/** Actual code generation */
	void gen_asm(ostream &o, BackendStrategy* backend); /**< x86 assembly code generation for this IR instruction */

	const Operation & getOp() const;
	const vector<string> & getParams() const;

	BasicBlock * getContainingBasicBlock() const;

	SymbolTable * getSymbolTable() const;

 private:
	BasicBlock* bb; /**< The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to */
	Operation op;
	Type *t;
	vector<string> params; /**< For 3-op instrs: d, x, y; for ldconst: d, c;  For call: label, d, params;  for wmem and rmem: choose yourself */
	// if you subclass IRInstr, each IRInstr subclass has its parameters and the previous (very important) comment becomes useless: it would be a better design.
};






/**  The class for a basic block */

/* A few important comments.
	 IRInstr has no jump instructions.
	 cmp_* instructions behaves as an arithmetic two-operand instruction (add or mult),
	  returning a boolean value (as an int)

	 Assembly jumps are generated as follows:
	 BasicBlock::gen_asm() first calls IRInstr::gen_asm() on all its instructions, and then
		if  exit_true  is a  nullptr,
            the epilogue is generated
        else if exit_false is a nullptr,
          an unconditional jmp to the exit_true branch is generated
		else (we have two successors, hence a branch)
          an instruction comparing the value of test_var_name to true is generated,
					followed by a conditional branch to the exit_false branch,
					followed by an unconditional branch to the exit_true branch
	 The attribute test_var_name itself is defined when converting
  the if, while, etc of the AST  to IR.

Possible optimization:
     a cmp_* comparison instructions, if it is the last instruction of its block,
       generates an actual assembly comparison
       followed by a conditional jump to the exit_false branch
*/

class BasicBlock {
 public:
	BasicBlock(CFG* cfg, string entry_label);
	BasicBlock(CFG* cfg, string entry_label, BasicBlock & parentBasicBlock);
	void gen_asm(ostream &o, BackendStrategy *backend);

	void add_IRInstr(IRInstr::Operation op, Type * t, vector<string> params);

	// No encapsulation whatsoever here. Feel free to do better.
	BasicBlock* exit_true;  /**< pointer to the next basic block, true branch. If nullptr, return from procedure */
	BasicBlock* exit_false; /**< pointer to the next basic block, false branch. If null_ptr, the basic block ends with an unconditional jump */
	string label; /**< label of the BB, also will be the label in the generated code */
	CFG* cfg; /** < the CFG where this block belongs */
	vector<IRInstr*> instrs; /** < the instructions themselves. */
  	string test_var_name;  /** < when generating IR code for an if(expr) or while(expr) etc,
													 store here the name of the variable that holds the value of expr */

	BasicBlock * parentBb;

	SymbolTable* symbolTable;

 protected:

};




/** The class for the control flow graph, also includes the symbol table */

/* A few important comments:
	 The entry block is the one with the same label as the AST function name.
	   (it could be the first of bbs, or it could be defined by an attribute value)
	 The exit block is the one with both exit pointers equal to nullptr.
     (again it could be identified in a more explicit way)

 */
class CFG {
 public:
	CFG();

	CFG(BackendStrategy * backend_strategy, string functionName);

	void add_bb(BasicBlock* bb);

	void add_exit_falseBB (BasicBlock * ifBb, BasicBlock * newBb, BasicBlock * defaultBb); 

	// x86 code generation: could be encapsulated in a processor class in a retargetable compiler
	void gen_asm(ostream& o) const;
	// string IR_reg_to_asm(string reg); /**< helper method: inputs a IR reg or input variable, returns e.g. "-24(%rbp)" for the proper value of 24 */
	void gen_asm_prologue(ostream& o) const;
	void gen_asm_epilogue(ostream& o) const;

	// symbol table methods
	void add_to_symbol_table(string name, Type *t);
	string create_new_tempvar(Type * t);
	int get_var_index(string name);
	Type* get_var_type(string name);

	// basic block management
	string new_BB_name();
	BasicBlock* current_bb;

	void setReturnInstructionPresent();

	bool isReturnStatementPresent() const;

	void errorFound();

	bool getHasError() const; 

	string getFunctionName() const;
	vector <BasicBlock*> bbs; /**< all the basic blocks of this CFG*/

 protected:
	map <string, Type*> SymbolType; /**< part of the symbol table  */
	map <string, int> SymbolIndex; /**< part of the symbol table  */
	int nextFreeSymbolIndex; /**< to allocate new symbols in the symbol table */
	int nextBBnumber; /**< just for naming */

	BackendStrategy * backend; /**< The assembly generation strategy. Depends on the target architecture */

	bool hasReturnStatement = false;
	bool hasError = false;

	string functionName;
};
