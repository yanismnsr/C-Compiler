#pragma once

#include <map>
#include <fstream> // std::ifstream

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"

using namespace std;

const string WARNING_FILE_RELATIVE_PATH = "warnings.txt";


class CodeGenVisitor : public ifccBaseVisitor {
private:
	map<string, int> variableToMemoryMap;
	bool returnPresent = false;
	int nbTemporaryVariable = 0;
	ofstream warningsFile;

public:
	// virtual std::any visitProg(ifccParser::ProgContext *ctx) override;

	virtual std::any visitProgBegin(ifccParser::ProgBeginContext *ctx) override;

	virtual std::any visitProgEnd(ifccParser::ProgEndContext *context) override;

	// virtual std::any visitRetConst(ifccParser::RetConstContext *ctx) override ;

	virtual std::any visitDeclaration(ifccParser::DeclarationContext *ctx) override;

	virtual std::any visitReturn(ifccParser::ReturnContext *ctx) override;

	virtual std::any visitAddmin(ifccParser::AddminContext *ctx) override;

	virtual std::any visitMultdiv(ifccParser::MultdivContext *ctx) override;

	virtual std::any visitParenthesis(ifccParser::ParenthesisContext *ctx) override;

	virtual std::any visitUnaryMinus(ifccParser::UnaryMinusContext *ctx) override;

	virtual std::any visitExprConst(ifccParser::ExprConstContext *ctx) override;

	virtual std::any visitExprIdentifier(ifccParser::ExprIdentifierContext *ctx) override;

	virtual std::any visitAffectation(ifccParser::AffectationContext *ctx) override;

};

// virtual std::any visitDeclareVar(ifccParser::DeclareVarContext *ctx) override ;
