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


CodeGenVisitor::CodeGenVisitor(BackendStrategy * backendStrategy)
{
	this->cfg = CFG(backendStrategy);
}

std::any CodeGenVisitor::visitProgBegin(ifccParser::ProgBeginContext *ctx)
{

	BasicBlock* prologue = new BasicBlock(&this->cfg, "prologue");
	this->cfg.add_bb(prologue);

	BasicBlock* bb = new BasicBlock(&this->cfg, "_main");
	this->cfg.add_bb(bb);

	return visitChildren(ctx);
}

std::any CodeGenVisitor::visitProgEnd(ifccParser::ProgEndContext *ctx)
{
	BasicBlock* epilogue = new BasicBlock(&this->cfg, "epilogue");
	this->cfg.add_bb(epilogue);

	return visitChildren(ctx);
}

std::any CodeGenVisitor::visitIf(ifccParser::IfContext *ctx)
{
    auto *endIfBB = new BasicBlock(cfg, cfg->new_BB_name());
    endIfBB->exit_true = testBB->exit_true;
    endIfBB->exit_false = testBB->exit_false;

    auto *thenBB = new BasicBlock(cfg, cfg->new_BB_name());

    BasicBlock *elseBB = endIfBB;
    if (falseCodeBlock != nullptr) {
        elseBB = new BasicBlock(cfg, cfg->new_BB_name());
        testBB->exit_false = elseBB;
    } else {
        testBB->exit_false = endIfBB;
    }
    return visitChildren(ctx);
}

std::any CodeGenVisitor::visitElse(ifccParser::ElseContext *ctx)
{
    return visitChildren(ctx);
}

std::any CodeGenVisitor::visitReturnexp(ifccParser::ReturnexpContext *ctx)
{
	this->returnPresent = true;

	BasicBlock * bb = this->cfg.current_bb;

	string exprVarName = any_cast<string>(visit(ctx->expr()));

	// void type
	PrimitiveType* pt = PrimitiveType::getInstance();
	Type * voidType = pt->getType("void");
	bb->add_IRInstr(IRInstr::Operation::returnVar, voidType, {exprVarName});

	return 0;
}

std::any CodeGenVisitor::visitDeclaration(ifccParser::DeclarationContext *ctx)
{

	SymbolTable * symbolTable = this->getSymbolTableOfCurrentBlock();

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

	return visitChildren(ctx);
}

std::any CodeGenVisitor::visitAddmin(ifccParser::AddminContext *ctx)
{
	SymbolTable * symbolTable = this->getSymbolTableOfCurrentBlock();

	string oper = ctx->op->getText();
	string expr1VarName = any_cast<string>(visit(ctx->expr(0)));
	string expr2VarName = any_cast<string>(visit(ctx->expr(1)));
	
	Symbol temporarySymbolAdded = symbolTable->addTemporaryVariable();

	PrimitiveType* pt = PrimitiveType::getInstance();
	Type * intType = pt->getType("int");

	if (oper == "+") { 	// Addition
		this->cfg.current_bb->add_IRInstr(IRInstr::Operation::add, intType, {temporarySymbolAdded.symbolName, expr1VarName, expr2VarName});
	}
	else { 				// Subtraction
		this->cfg.current_bb->add_IRInstr(IRInstr::Operation::sub, intType, {temporarySymbolAdded.symbolName, expr1VarName, expr2VarName});
	}

	return temporarySymbolAdded.symbolName;
}

std::any CodeGenVisitor::visitMultdiv(ifccParser::MultdivContext *ctx)
{
	SymbolTable * symbolTable = this->getSymbolTableOfCurrentBlock();

	string oper = ctx->op->getText();

	string expr1VarName = any_cast<string>(visit(ctx->expr(0)));
	string expr2VarName = any_cast<string>(visit(ctx->expr(1)));

	Symbol temporarySymbolAdded = symbolTable->addTemporaryVariable();

	// get basic block
	BasicBlock * bb = this->cfg.current_bb;

	if (oper == "*") { 						// Multiplication
		Type * intType = PrimitiveType::getInstance()->getType("int");
		bb->add_IRInstr(IRInstr::Operation::mul, intType, {temporarySymbolAdded.symbolName, expr1VarName, expr2VarName});
	}
	else { 									// Division
		Type * intType = PrimitiveType::getInstance()->getType("int");
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
	SymbolTable * symbolTable = this->getSymbolTableOfCurrentBlock();

	// Get constant value
	int number = stoi(ctx->CONST()->getText());

	// Store constant in a temporary variable in symbol table
	Symbol temporarySymbolAdded = symbolTable->addTemporaryVariable();

	// Get basic block
	BasicBlock* bb = this->cfg.current_bb;

	// Add IR to basic block
	Type * intType = PrimitiveType::getInstance()->getType("int");
	bb->add_IRInstr(IRInstr::Operation::ldconst, intType, {to_string(number), temporarySymbolAdded.symbolName});

	// Return temporary variable name in which the constant is stored
	return (string)temporarySymbolAdded.symbolName;
}

std::any CodeGenVisitor::visitParenthesis(ifccParser::ParenthesisContext *ctx)
{
	return any_cast<string>(visit(ctx->expr()));
}

std::any CodeGenVisitor::visitUnaryExpression(ifccParser::UnaryExpressionContext *ctx) {

	SymbolTable * symbolTable = this->getSymbolTableOfCurrentBlock();

	string oper = ctx->op->getText();

	string exprVarName = any_cast<string>(visit(ctx->expr()));

	Symbol temporarySymbolAdded = symbolTable->addTemporaryVariable();

	// get the basic block
	BasicBlock * bb = this->cfg.current_bb;

	// int variableAddress = variableToMemoryMap[exprVarName] * -4;

	if (oper == "-") {

		Type * intType = PrimitiveType::getInstance()->getType("int");
		bb->add_IRInstr(IRInstr::Operation::sub, intType, {temporarySymbolAdded.symbolName, "0", exprVarName});

		return (string)temporarySymbolAdded.symbolName;

	} else
	{
		return exprVarName;
	}
}

std::any CodeGenVisitor::visitAffectation(ifccParser::AffectationContext *ctx)
{
	SymbolTable * symbolTable = this->getSymbolTableOfCurrentBlock();

	string variableName = ctx->IDENTIFIER()->getText();
	string rValueVariableName = any_cast<string>(visit(ctx->expr()));

	BasicBlock* bb = this->cfg.current_bb;
	PrimitiveType* pt = PrimitiveType::getInstance();
	Type * intType = pt->getType("int");
	bb->add_IRInstr(IRInstr::Operation::copy, intType, {rValueVariableName, variableName});

	symbolTable->setVariableIsInitialized(variableName, true);

	return 0;
}

const CFG & CodeGenVisitor::getCFG() const {
	return this->cfg;
}

SymbolTable * CodeGenVisitor::getSymbolTableOfCurrentBlock() {
	return this->cfg.current_bb->symbolTable;
}