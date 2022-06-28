#include "CodeGenVisitor.h"
#include "antlr4-runtime.h"
#include "./generated/ifccVisitor.h"
#include "./SymbolTable.h"
#include <iostream>
#include <map>
#include <any>
#include "./models/Type.h"
#include "./IR/IR.h"

using namespace std;

CodeGenVisitor::CodeGenVisitor(BackendStrategy *backendStrategy)
{
	this->strategy = backendStrategy;
}

std::any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx)
{
	auto visitResult = visitChildren(ctx);

	return visitResult;
}

std::any CodeGenVisitor::visitFunction(ifccParser::FunctionContext *ctx) {
	string functionName = ctx->IDENTIFIER()->getText();

	if (functionName == "main") {
		#ifdef __APPLE__
			functionName = "_main";
		#endif
	}
	CFG * newCfg = new CFG(this->strategy, functionName);
	this->addCfg(newCfg);

	BasicBlock *prologue = new BasicBlock(this->currentCfg, "prologue");
	this->currentCfg->add_bb(prologue);

	this->currentCfg->epilogue = new BasicBlock(this->currentCfg, "epilogue");
	this->currentCfg->add_bb(this->currentCfg->epilogue);


	this->currentCfg->current_bb = prologue;
	prologue->exit_true = nullptr;
	this->currentCfg->epilogue->exit_true = nullptr;

	return visitChildren(ctx);
}

void CodeGenVisitor::addCfg(CFG* newCfg) {
	this->cfgs.push_back(newCfg);
	this->currentCfg = newCfg;
}

std::any CodeGenVisitor::visitIfInstr(ifccParser::IfInstrContext *ctx)
{
	// TODO correct the chaining of the blocks

	// Current basic block
	BasicBlock *currentBasicBlock = this->currentCfg->current_bb;

	// Generate if basic block 
	BasicBlock * ifBb = new BasicBlock(currentCfg, currentCfg->new_BB_name() + "ifbb", *currentBasicBlock);
	this->currentCfg->add_bb(ifBb);
 	string testResultVariableName = any_cast<string>(visit(ctx->expr()));

	Symbol tempVariable = currentCfg->current_bb->symbolTable->addTemporaryVariable();
	PrimitiveType *pt = PrimitiveType::getInstance();
	Type *boolType = pt->getType("bool");
	ifBb->add_IRInstr(IRInstr::Operation::cmp_eq, boolType, {tempVariable.symbolName, testResultVariableName, "0"});

	// Generate true block
	BasicBlock * trueBlock = new BasicBlock(currentCfg, currentCfg->new_BB_name() + "trueBb", *this->currentCfg->current_bb);
	this->currentCfg->add_bb(trueBlock);
	this->previousBlockIsIfBlock = true;
	if (ctx->instr()) {
		visit(ctx->instr());
	} else {
		visit(ctx->block());
	}
	trueBlock = this->currentCfg->current_bb;

	BasicBlock * falseBb = nullptr;
	if (ctx->elseInstr()) {

		// False block
		falseBb = new BasicBlock(currentCfg, currentCfg->new_BB_name() + "falseBb", *currentBasicBlock);
		this->currentCfg->add_exit_falseBB(ifBb, falseBb);
		this->previousBlockIsIfBlock = true;
		this->endOfBlock = false;
		visit(ctx->elseInstr());
		falseBb = this->currentCfg->current_bb;

	}

	BasicBlock * defaultBb = new BasicBlock(currentCfg, currentCfg->new_BB_name()+ "defaultBb", *currentBasicBlock);
	this->currentCfg->add_bb(defaultBb);
	if (trueBlock->exit_true != this->currentCfg->epilogue) {
		trueBlock->exit_true = defaultBb;
	}
	if (falseBb && falseBb->exit_true != this->currentCfg->epilogue) {
		falseBb->exit_true = defaultBb;
	} else {
		ifBb->exit_false = defaultBb;
	}

	this->currentCfg->current_bb = defaultBb;
	this->endOfBlock = false;
	// this->endOfBlock = true;

	return (string)testResultVariableName;
}

std::any CodeGenVisitor::visitWhileInstr(ifccParser::WhileInstrContext *ctx)
{
    // Current basic block
    BasicBlock *currentBasicBlock = this->currentCfg->current_bb;

    // Generate while condition basic block
    BasicBlock * whileConditionBb = new BasicBlock(currentCfg, currentCfg->new_BB_name(), *currentBasicBlock);
    this->currentCfg->add_bb(whileConditionBb);
    string testResultVariableName = any_cast<string>(visit(ctx->expr()));

    Symbol tempVariable = this->currentCfg->current_bb->symbolTable->addTemporaryVariable();
    PrimitiveType *pt = PrimitiveType::getInstance();
    Type *boolType = pt->getType("bool");
    whileConditionBb->add_IRInstr(IRInstr::Operation::cmp_eq, boolType, {tempVariable.symbolName, testResultVariableName, "0"});

    // Generate while body block
    BasicBlock * trueBlock = new BasicBlock(currentCfg, currentCfg->new_BB_name(), *this->currentCfg->current_bb);
    this->currentCfg->add_bb(trueBlock);
    this->previousBlockIsIfBlock = true;
    if (ctx->instr()) {
        visit(ctx->instr());
    } else {
        visit(ctx->block());
    }
    // trueBlock->exit_true = whileConditionBb; // recheck while condition

	this->currentCfg->current_bb->exit_true = whileConditionBb;

    // // Exit default block
	this->currentCfg->current_bb = whileConditionBb;
    BasicBlock * defaultBb = new BasicBlock(currentCfg, currentCfg->new_BB_name(), *whileConditionBb);
    this->currentCfg->add_exit_falseBB(whileConditionBb, defaultBb);

    // this->currentCfg->current_bb = defaultBb;
    this->endOfBlock = true;

    return (string)testResultVariableName;

}

std::any CodeGenVisitor::visitBlock(ifccParser::BlockContext *ctx)
{

	// TODO implement this function
	if (!this->previousBlockIsIfBlock) {
		BasicBlock * bb = new BasicBlock(this->currentCfg, this->currentCfg->new_BB_name(), *this->currentCfg->current_bb);
		this->currentCfg->add_bb(bb);
	} else {
		this->previousBlockIsIfBlock = false;
	}

	auto result = visitChildren(ctx);

	this->endOfBlock = true;

	// BasicBlock * otherBb = new BasicBlock(this->currentCfg, this->currentCfg->new_BB_name(), *this->currentCfg->current_bb);
	// this->currentCfg->add_bb(otherBb);
	return result;
}

std::any CodeGenVisitor::visitSimpleComparison(ifccParser::SimpleComparisonContext *ctx)
{
	
	BasicBlock * currentBb = this->currentCfg->current_bb;
	// get comparisonOperator
	string comparisonOperator = ctx->COMPARISONOPERATOR()->getText();

	// Get operands names 
	string operand1 = any_cast<string>(visit(ctx->expr(0)));
	string operand2 = any_cast<string>(visit(ctx->expr(1)));

	// Temporary variable
	SymbolTable *symbolTable = this->getSymbolTableOfCurrentBlock();
	Symbol symbol = symbolTable->addTemporaryVariable();	

	PrimitiveType *pt = PrimitiveType::getInstance();
	Type *boolType = pt->getType("bool");

	if (comparisonOperator == "==") {
		currentBb->add_IRInstr(IRInstr::Operation::cmp_eq, boolType, {symbol.symbolName, operand1, operand2});
	} else if (comparisonOperator == "<") {
		currentBb->add_IRInstr(IRInstr::Operation::cmp_lt, boolType, {symbol.symbolName, operand1, operand2});
	} else if (comparisonOperator == "<=") {
		currentBb->add_IRInstr(IRInstr::Operation::cmp_le, boolType, {symbol.symbolName, operand1, operand2});
	} else if (comparisonOperator == ">") {
		currentBb->add_IRInstr(IRInstr::Operation::cmp_gt, boolType, {symbol.symbolName, operand1, operand2});
	} else if (comparisonOperator == ">=") {
		currentBb->add_IRInstr(IRInstr::Operation::cmp_ge, boolType, {symbol.symbolName, operand1, operand2});
	} else if (comparisonOperator == "!=") {
		currentBb->add_IRInstr(IRInstr::Operation::cmp_ne, boolType, {symbol.symbolName, operand1, operand2});
	}

	return (string)symbol.symbolName;
}

std::any CodeGenVisitor::visitMultipleOperatorsComparison(ifccParser::MultipleOperatorsComparisonContext *ctx) {
	// TODO implement this function

	BasicBlock * currentBb = this->currentCfg->current_bb;

	string operand1 = any_cast<string>(visit(ctx->expr(0)));
	string operand2 = any_cast<string>(visit(ctx->expr(1)));

	// Temporary variable
	SymbolTable *symbolTable = this->getSymbolTableOfCurrentBlock();
	Symbol symbol = symbolTable->addTemporaryVariable();

	string comparisonOperator = ctx->CONDOPERATORS()->getText();

	PrimitiveType *pt = PrimitiveType::getInstance();
	Type *boolType = pt->getType("bool");

	if (comparisonOperator == "&") {
		currentBb->add_IRInstr(IRInstr::Operation::andop, boolType, {symbol.symbolName, operand1, operand2});
	} else if (comparisonOperator == "|"){
		currentBb->add_IRInstr(IRInstr::Operation::orop, boolType, {symbol.symbolName, operand1, operand2});
	}

	return (string) symbol.symbolName;
}


std::any CodeGenVisitor::visitElseInstr(ifccParser::ElseInstrContext *ctx)
{
	return visitChildren(ctx);
}

std::any CodeGenVisitor::visitReturnexp(ifccParser::ReturnexpContext *ctx)
{
	this->returnPresent = true;

	BasicBlock *bb = this->currentCfg->current_bb;

	string exprVarName = any_cast<string>(visit(ctx->expr()));

	// void type
	PrimitiveType *pt = PrimitiveType::getInstance();
	Type *voidType = pt->getType("void");
	bb->add_IRInstr(IRInstr::Operation::returnVar, voidType, {exprVarName});

	bb->exit_true = this->currentCfg->epilogue;
	this->currentCfg->previousBlockIsReturnBlock = true;

	return 0;
}

std::any CodeGenVisitor::visitDeclaration(ifccParser::DeclarationContext *ctx)
{

	SymbolTable *symbolTable = this->getSymbolTableOfCurrentBlock();

	std::vector<antlr4::tree::TerminalNode *> onlyDeclarations = ctx->IDENTIFIER();
	std::vector<ifccParser::AffectationContext *> declarationsWithAffectations = ctx->affectation();
	for (auto onlyDeclaration : onlyDeclarations)
	{
		string variableName = onlyDeclaration->getText();
		symbolTable->addVariable(variableName);
	}

	for (auto declarationWithAffectation : declarationsWithAffectations)
	{
		string variableName = declarationWithAffectation->IDENTIFIER()->getText();
		symbolTable->addVariable(variableName);
		visit(declarationWithAffectation);
	}

	return 0;
}

std::any CodeGenVisitor::visitAddmin(ifccParser::AddminContext *ctx)
{
	SymbolTable *symbolTable = this->getSymbolTableOfCurrentBlock();

	string oper = ctx->op->getText();
	string expr1VarName = any_cast<string>(visit(ctx->expr(0)));
	string expr2VarName = any_cast<string>(visit(ctx->expr(1)));

	Symbol temporarySymbolAdded = symbolTable->addTemporaryVariable();

	PrimitiveType *pt = PrimitiveType::getInstance();
	Type *intType = pt->getType("int");

	if (oper == "+")
	{ // Addition
		this->currentCfg->current_bb->add_IRInstr(IRInstr::Operation::add, intType, {temporarySymbolAdded.symbolName, expr1VarName, expr2VarName});
	}
	else
	{ // Subtraction
		this->currentCfg->current_bb->add_IRInstr(IRInstr::Operation::sub, intType, {temporarySymbolAdded.symbolName, expr1VarName, expr2VarName});
	}

	return temporarySymbolAdded.symbolName;
}

std::any CodeGenVisitor::visitMultdiv(ifccParser::MultdivContext *ctx)
{
	SymbolTable *symbolTable = this->getSymbolTableOfCurrentBlock();

	string oper = ctx->op->getText();

	string expr1VarName = any_cast<string>(visit(ctx->expr(0)));
	string expr2VarName = any_cast<string>(visit(ctx->expr(1)));

	Symbol temporarySymbolAdded = symbolTable->addTemporaryVariable();

	// get basic block
	BasicBlock *bb = this->currentCfg->current_bb;

	if (oper == "*")
	{ // Multiplication
		Type *intType = PrimitiveType::getInstance()->getType("int");
		bb->add_IRInstr(IRInstr::Operation::mul, intType, {temporarySymbolAdded.symbolName, expr1VarName, expr2VarName});
	}
	else
	{ // Division
		Type *intType = PrimitiveType::getInstance()->getType("int");
		bb->add_IRInstr(IRInstr::Operation::div, intType, {temporarySymbolAdded.symbolName, expr1VarName, expr2VarName});
	}

	return temporarySymbolAdded.symbolName;
}

std::any CodeGenVisitor::visitExprIdentifier(ifccParser::ExprIdentifierContext *ctx)
{
	return (string)ctx->IDENTIFIER()->getText();
}

std::any CodeGenVisitor::visitExprConst(ifccParser::ExprConstContext *ctx)
{
	SymbolTable *symbolTable = this->getSymbolTableOfCurrentBlock();

	// Get constant value
	int number = stoi(ctx->CONST()->getText());

	// Store constant in a temporary variable in symbol table
	Symbol temporarySymbolAdded = symbolTable->addTemporaryVariable();

	// Get basic block
	BasicBlock *bb = this->currentCfg->current_bb;

	// Add IR to basic block
	Type *intType = PrimitiveType::getInstance()->getType("int");
	bb->add_IRInstr(IRInstr::Operation::ldconst, intType, {to_string(number), temporarySymbolAdded.symbolName});

	// Return temporary variable name in which the constant is stored
	return (string)temporarySymbolAdded.symbolName;
}

std::any CodeGenVisitor::visitParenthesis(ifccParser::ParenthesisContext *ctx)
{
	return any_cast<string>(visit(ctx->expr()));
}

std::any CodeGenVisitor::visitUnaryExpression(ifccParser::UnaryExpressionContext *ctx)
{

	SymbolTable *symbolTable = this->getSymbolTableOfCurrentBlock();

	string oper = ctx->op->getText();

	string exprVarName = any_cast<string>(visit(ctx->expr()));

	Symbol temporarySymbolAdded = symbolTable->addTemporaryVariable();

	// get the basic block
	BasicBlock *bb = this->currentCfg->current_bb;

	// int variableAddress = variableToMemoryMap[exprVarName] * -4;

	if (oper == "-")
	{

		Type *intType = PrimitiveType::getInstance()->getType("int");
		bb->add_IRInstr(IRInstr::Operation::sub, intType, {temporarySymbolAdded.symbolName, "0", exprVarName});

		return (string)temporarySymbolAdded.symbolName;
	}
	else
	{
		return exprVarName;
	}
}

std::any CodeGenVisitor::visitAffectation(ifccParser::AffectationContext *ctx)
{
	SymbolTable *symbolTable = this->getSymbolTableOfCurrentBlock();

	string variableName = ctx->IDENTIFIER()->getText();
	string rValueVariableName = any_cast<string>(visit(ctx->expr()));

	BasicBlock *bb = this->currentCfg->current_bb;
	PrimitiveType *pt = PrimitiveType::getInstance();
	Type *intType = pt->getType("int");
	bb->add_IRInstr(IRInstr::Operation::copy, intType, {rValueVariableName, variableName});
	symbolTable->setVariableIsInitialized(variableName, true);

	return "0";
}

const CFG &CodeGenVisitor::getCFG() const
{
	return *this->currentCfg;
}

SymbolTable *CodeGenVisitor::getSymbolTableOfCurrentBlock()
{
	return this->currentCfg->current_bb->symbolTable;
}

std::any CodeGenVisitor::visitInstr(ifccParser::InstrContext *ctx) {

	if (this->endOfBlock) {
		BasicBlock * parentBB = this->currentCfg->current_bb->parentBb;
		BasicBlock * newBb = new BasicBlock(this->currentCfg, this->currentCfg->new_BB_name(), *parentBB);
		this->currentCfg->add_bb(newBb);
		this->endOfBlock = false;
	}

	if (this->currentCfg->previousBlockIsReturnBlock) {
		this->currentCfg->previousBlockIsReturnBlock = false;
	}

	return visitChildren(ctx);

}


std::any CodeGenVisitor::visitXorOperation(ifccParser::XorOperationContext *ctx) {

	SymbolTable *symbolTable = this->getSymbolTableOfCurrentBlock();

	string expr1VarName = any_cast<string>(visit(ctx->expr(0)));
	string expr2VarName = any_cast<string>(visit(ctx->expr(1)));

	Symbol temporarySymbolAdded = symbolTable->addTemporaryVariable();

	PrimitiveType *pt = PrimitiveType::getInstance();
	Type *intType = pt->getType("int");

	this->currentCfg->current_bb->add_IRInstr(IRInstr::Operation::xorOp, intType, {temporarySymbolAdded.symbolName, expr1VarName, expr2VarName});
	
	return (string)temporarySymbolAdded.symbolName;
}

std::any CodeGenVisitor::visitFunctionCallExpr(ifccParser::FunctionCallExprContext *ctx) {
	return visitChildren(ctx);;
}


void CodeGenVisitor::generateAssembly (ostream & o) {
	for (CFG* cfg : this->cfgs) {
		cfg->gen_asm(o);
	}
}


std::any CodeGenVisitor::visitFunctionCall(ifccParser::FunctionCallContext *ctx) {

	string functionName = ctx->IDENTIFIER()->getText();

	SymbolTable *symbolTable = this->getSymbolTableOfCurrentBlock();
	Symbol temporarySymbolAdded = symbolTable->addTemporaryVariable();

	PrimitiveType *pt = PrimitiveType::getInstance();
	Type *voidType = pt->getType("void");

	this->currentCfg->current_bb->add_IRInstr(IRInstr::Operation::call, voidType, {temporarySymbolAdded.symbolName, functionName});

	visitChildren(ctx);

	return (string) temporarySymbolAdded.symbolName;
}