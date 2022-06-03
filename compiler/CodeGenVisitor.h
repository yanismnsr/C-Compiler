#pragma once

#include <map>

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"

using namespace std;


class  CodeGenVisitor : public ifccBaseVisitor {

	private :
		map <string, int> variableToMemoryMap;
		bool returnPresent = false;

	public:
		virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override ;

		virtual antlrcpp::Any visitProgBegin(ifccParser::ProgBeginContext *ctx) override ;

		virtual antlrcpp::Any visitProgEnd(ifccParser::ProgEndContext *context) override ;

		virtual antlrcpp::Any visitVarvar(ifccParser::VarvarContext *ctx) override ;

		// virtual antlrcpp::Any visitRetConst(ifccParser::RetConstContext *ctx) override ;

		virtual antlrcpp::Any visitDeclaration(ifccParser::DeclarationContext *ctx) override ;

		virtual antlrcpp::Any visitVarconst(ifccParser::VarconstContext *ctx) override ;

		virtual antlrcpp::Any visitReturn(ifccParser::ReturnContext *ctx) override ;

		// virtual std::any visitDeclareVar(ifccParser::DeclareVarContext *ctx) override ;

};

