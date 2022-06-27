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
	string main = "main";

	#ifdef __APPLE__
		main = "_main";
	#endif
	this->cfg = CFG(backendStrategy, main);
}

std::any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx)
{
	BasicBlock *prologue = new BasicBlock(&this->cfg, "prologue");
	this->cfg.add_bb(prologue);

	BasicBlock *epilogue = new BasicBlock(&this->cfg, "epilogue");
	this->cfg.add_bb(epilogue);
	epilogue->exit_true = nullptr;

	prologue->exit_true = epilogue;
	this->cfg.current_bb = prologue;

	auto visitResult = visitChildren(ctx);

	return visitResult;
}



std::any CodeGenVisitor::visitIfInstr(ifccParser::IfInstrContext *ctx)
{
	// TODO correct the chaining of the blocks

	// Current basic block
	BasicBlock *currentBasicBlock = this->cfg.current_bb;

	// Generate if basic block 
	BasicBlock * ifBb = new BasicBlock(&cfg, cfg.new_BB_name(), *currentBasicBlock);
	this->cfg.add_bb(ifBb);
 	string testResultVariableName = any_cast<string>(visit(ctx->comparison()));

	Symbol tempVariable = currentBasicBlock->symbolTable->addTemporaryVariable();
	PrimitiveType *pt = PrimitiveType::getInstance();
	Type *boolType = pt->getType("bool");
	ifBb->add_IRInstr(IRInstr::Operation::cmp_eq, boolType, {tempVariable.symbolName, testResultVariableName, "0"});


	// Generate true block
	BasicBlock * trueBlock = new BasicBlock(&cfg, cfg.new_BB_name(), *this->cfg.current_bb);
	this->cfg.add_bb(trueBlock);
	this->previousBlockIsIfBlock = true;
	if (ctx->instr()) {
		visit(ctx->instr());
	} else {
		visit(ctx->block());
	}

	// Else default block
	BasicBlock * defaultBb = new BasicBlock(&cfg, cfg.new_BB_name(), *currentBasicBlock);
	this->cfg.add_bb(defaultBb);

	if (ctx->elseInstr()) {

		// False block
		BasicBlock * falseBb = new BasicBlock(&cfg, cfg.new_BB_name(), *currentBasicBlock);
		this->cfg.add_exit_falseBB(ifBb, falseBb, defaultBb);
		this->previousBlockIsIfBlock = true;
		visit(ctx->elseInstr());

	} else {
		ifBb->exit_false = defaultBb;
	}

	this->cfg.current_bb = defaultBb;
	this->endOfBlock = true;

	return (string)testResultVariableName;
}

std::any CodeGenVisitor::visitWhileInstr(ifccParser::WhileInstrContext *ctx)
{
    // Current basic block
    BasicBlock *currentBasicBlock = this->cfg.current_bb;

    // Generate while condition basic block
    BasicBlock * whileConditionBb = new BasicBlock(&cfg, cfg.new_BB_name(), *currentBasicBlock);
    this->cfg.add_bb(whileConditionBb);
    string testResultVariableName = any_cast<string>(visit(ctx->comparison()));

    Symbol tempVariable = currentBasicBlock->symbolTable->addTemporaryVariable();
    PrimitiveType *pt = PrimitiveType::getInstance();
    Type *boolType = pt->getType("bool");
    whileConditionBb->add_IRInstr(IRInstr::Operation::cmp_eq, boolType, {tempVariable.symbolName, testResultVariableName, "0"});

    // Generate while body block
    BasicBlock * trueBlock = new BasicBlock(&cfg, cfg.new_BB_name(), *this->cfg.current_bb);
    this->cfg.add_bb(trueBlock);
    this->previousBlockIsIfBlock = true;
    if (ctx->instr()) {
        visit(ctx->instr());
    } else {
        visit(ctx->block());
    }
    trueBlock->exit_true = whileConditionBb; // recheck while condition

    // Exit default block
    BasicBlock * defaultBb = new BasicBlock(&cfg, cfg.new_BB_name(), *whileConditionBb);
    this->cfg.add_bb(defaultBb);
    //whileConditionBb->exit_false = defaultBb;
    this->cfg.add_exit_falseBB(whileConditionBb, falseBb, defaultBb);

    this->cfg.current_bb = defaultBb;
    this->endOfBlock = true;

    return (string)testResultVariableName;

}

std::any CodeGenVisitor::visitBlock(ifccParser::BlockContext *ctx)
{

	// TODO implement this function
	if (!this->previousBlockIsIfBlock) {
		BasicBlock * bb = new BasicBlock(&this->cfg, this->cfg.new_BB_name(), *this->cfg.current_bb);
		this->cfg.add_bb(bb);
	} else {
		this->previousBlockIsIfBlock = false;
	}

	auto result = visitChildren(ctx);

	this->endOfBlock = true;

	// BasicBlock * otherBb = new BasicBlock(&this->cfg, this->cfg.new_BB_name(), *this->cfg.current_bb);
	// this->cfg.add_bb(otherBb);
	return result;
}

std::any CodeGenVisitor::visitSimpleComparison(ifccParser::SimpleComparisonContext *ctx)
{
	
	BasicBlock * currentBb = this->cfg.current_bb;
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

std::any CodeGenVisitor::visitUnaryComparison(ifccParser::UnaryComparisonContext *ctx) {
	return visitChildren(ctx);
}

std::any CodeGenVisitor::visitMultipleOperatorsComparison(ifccParser::MultipleOperatorsComparisonContext *ctx) {
	// TODO implement this function

	BasicBlock * currentBb = this->cfg.current_bb;

	string operand1 = any_cast<string>(visit(ctx->comparison(0)));
	string operand2 = any_cast<string>(visit(ctx->comparison(1)));

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

	BasicBlock *bb = this->cfg.current_bb;

	string exprVarName = any_cast<string>(visit(ctx->expr()));

	// void type
	PrimitiveType *pt = PrimitiveType::getInstance();
	Type *voidType = pt->getType("void");
	bb->add_IRInstr(IRInstr::Operation::returnVar, voidType, {exprVarName});

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
		this->cfg.current_bb->add_IRInstr(IRInstr::Operation::add, intType, {temporarySymbolAdded.symbolName, expr1VarName, expr2VarName});
	}
	else
	{ // Subtraction
		this->cfg.current_bb->add_IRInstr(IRInstr::Operation::sub, intType, {temporarySymbolAdded.symbolName, expr1VarName, expr2VarName});
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
	BasicBlock *bb = this->cfg.current_bb;

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
	BasicBlock *bb = this->cfg.current_bb;

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
	BasicBlock *bb = this->cfg.current_bb;

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

	BasicBlock *bb = this->cfg.current_bb;
	PrimitiveType *pt = PrimitiveType::getInstance();
	Type *intType = pt->getType("int");
	bb->add_IRInstr(IRInstr::Operation::copy, intType, {rValueVariableName, variableName});
	symbolTable->setVariableIsInitialized(variableName, true);

	return "0";
}

const CFG &CodeGenVisitor::getCFG() const
{
	return this->cfg;
}

SymbolTable *CodeGenVisitor::getSymbolTableOfCurrentBlock()
{
	return this->cfg.current_bb->symbolTable;
}

std::any CodeGenVisitor::visitInstr(ifccParser::InstrContext *ctx) {

	if (this->endOfBlock) {
		BasicBlock * parentBB = this->cfg.current_bb->parentBb;
		BasicBlock * newBb = new BasicBlock(&this->cfg, this->cfg.new_BB_name(), *parentBB);
		this->cfg.add_bb(newBb);
		this->endOfBlock = false;
	}

	return visitChildren(ctx);

}