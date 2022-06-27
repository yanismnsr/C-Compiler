#pragma once

#include <map>
#include <fstream> // std::ifstream

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include "./IR/IR.h"
#include "SymbolTable.h"

using namespace std;

const string WARNING_FILE_RELATIVE_PATH_2 = "warnings.txt";


class CodeGenVisitor : public ifccBaseVisitor {
private:
	bool returnPresent = false;
	int nbTemporaryVariable = 0;
	CFG cfg;

	bool endOfBlock = false; 		// State variable to say that we just closed a block. It means that the 
									// next instruction has to create a new block
	
	bool previousBlockIsIfBlock = false; 	// State variable to say that the current block is a successor of an if
											// Block. This means that the current block is meant to be created in 
											// the visitIfInstr function. No need to create a new block then 

public:

	CodeGenVisitor(BackendStrategy * backendStrategy);

	virtual std::any visitProg(ifccParser::ProgContext *ctx) override;

	virtual std::any visitDeclaration(ifccParser::DeclarationContext *ctx) override;

	virtual std::any visitReturnexp(ifccParser::ReturnexpContext *ctx) override;

	virtual std::any visitAddmin(ifccParser::AddminContext *ctx) override;

	virtual std::any visitMultdiv(ifccParser::MultdivContext *ctx) override;

	virtual std::any visitParenthesis(ifccParser::ParenthesisContext *ctx) override;

  	virtual std::any visitIfInstr(ifccParser::IfInstrContext *ctx) override;

    virtual std::any visitWhileInstr(ifccParser::WhileInstrContext *ctx) override;

	virtual std::any visitBlock(ifccParser::BlockContext *ctx) override ;

	virtual std::any visitExprConst(ifccParser::ExprConstContext *ctx) override;

	virtual std::any visitExprIdentifier(ifccParser::ExprIdentifierContext *ctx) override;

	virtual std::any visitAffectation(ifccParser::AffectationContext *ctx) override;

	virtual std::any visitUnaryExpression(ifccParser::UnaryExpressionContext *ctx) override;

	virtual std::any visitElseInstr(ifccParser::ElseInstrContext *ctx) override;

	virtual std::any visitUnaryComparison(ifccParser::UnaryComparisonContext *ctx) override;

	virtual std::any visitSimpleComparison(ifccParser::SimpleComparisonContext *ctx) override;

	virtual std::any visitMultipleOperatorsComparison(ifccParser::MultipleOperatorsComparisonContext *ctx) override;

	virtual std::any visitInstr(ifccParser::InstrContext *ctx) override;

	const CFG & getCFG() const;

	SymbolTable * getSymbolTableOfCurrentBlock();

};