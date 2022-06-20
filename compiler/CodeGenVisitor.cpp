#include "CodeGenVisitor.h"
#include "antlr4-runtime.h"
#include "./generated/ifccVisitor.h"
#include "./SymbolList.h"
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
	string bbName = this->cfg.new_BB_name();
	BasicBlock* bb = new BasicBlock(&this->cfg, "_main");
	this->cfg.add_bb(bb);

	return visitChildren(ctx);
}

std::any CodeGenVisitor::visitProgEnd(ifccParser::ProgEndContext *ctx)
{
	return visitChildren(ctx);
}

std::any CodeGenVisitor::visitReturn(ifccParser::ReturnContext *ctx)
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
	std::vector<antlr4::tree::TerminalNode *> onlyDeclarations = ctx->IDENTIFIER();
	std::vector<ifccParser::AffectationContext *> declarationsWithAffectations = ctx->affectation();
	for (auto onlyDeclaration : onlyDeclarations)
	{
		string variableName = onlyDeclaration->getText();
		SymbolList::getInstance()->addVariable(variableName);
	}

	for (auto declarationWithAffectation : declarationsWithAffectations)
	{
		string variableName = declarationWithAffectation->IDENTIFIER()->getText();
		SymbolList::getInstance()->addVariable(variableName);
		visit(declarationWithAffectation);
	}

	return visitChildren(ctx);
}

std::any CodeGenVisitor::visitAddmin(ifccParser::AddminContext *ctx)
{
	string oper = ctx->op->getText();
	string expr1VarName = any_cast<string>(visit(ctx->expr(0)));
	string expr2VarName = any_cast<string>(visit(ctx->expr(1)));
	
	Symbol temporarySymbolAdded = SymbolList::getInstance()->addTemporaryVariable();

	PrimitiveType* pt = PrimitiveType::getInstance();
	Type * intType = pt->getType("int");

	if (oper == "+") { // Addition
		this->cfg.current_bb->add_IRInstr(IRInstr::Operation::add, intType, {temporarySymbolAdded.symbolName, expr1VarName, expr2VarName});
	}
	else { // Subtraction
		this->cfg.current_bb->add_IRInstr(IRInstr::Operation::sub, intType, {temporarySymbolAdded.symbolName, expr1VarName, expr2VarName});
	}

	return temporarySymbolAdded.symbolName;
}

std::any CodeGenVisitor::visitMultdiv(ifccParser::MultdivContext *ctx)
{
	string oper = ctx->op->getText();

	string expr1VarName = any_cast<string>(visit(ctx->expr(0)));
	string expr2VarName = any_cast<string>(visit(ctx->expr(1)));

	Symbol temporarySymbolAdded = SymbolList::getInstance()->addTemporaryVariable();

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
	// Get constant value
	int number = stoi(ctx->CONST()->getText());

	// Store constant in a temporary variable in symbol table
	Symbol temporarySymbolAdded = SymbolList::getInstance()->addTemporaryVariable();

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
	string oper = ctx->op->getText();

	string exprVarName = any_cast<string>(visit(ctx->expr()));

	Symbol temporarySymbolAdded = SymbolList::getInstance()->addTemporaryVariable();


	// get the basic block
	BasicBlock * bb = this->cfg.current_bb;

	// int variableAddress = variableToMemoryMap[exprVarName] * -4;

	if (oper == "-") {

		Type * intType = PrimitiveType::getInstance()->getType("int");
		bb->add_IRInstr(IRInstr::Operation::sub, PrimitiveType::getInstance()->getType("int"), {temporarySymbolAdded.symbolName, 0, exprVarName});

		return (string)temporarySymbolAdded.symbolName;

	} else
	{
		return exprVarName;
	}
}

std::any CodeGenVisitor::visitAffectation(ifccParser::AffectationContext *ctx)
{
	string variableName = ctx->IDENTIFIER()->getText();
	string rValueVariableName = any_cast<string>(visit(ctx->expr()));

	BasicBlock* bb = this->cfg.current_bb;
	PrimitiveType* pt = PrimitiveType::getInstance();
	Type * intType = pt->getType("int");
	bb->add_IRInstr(IRInstr::Operation::copy, intType, {rValueVariableName, variableName});

	SymbolList::getInstance()->setVariableIsInitialized(variableName, true);

	return 0;
}

const CFG & CodeGenVisitor::getCFG() const {
	return this->cfg;
}