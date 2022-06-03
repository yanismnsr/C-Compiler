#include "CodeGenVisitor.h"
#include "antlr4-runtime.h"
#include "./generated/ifccVisitor.h"
#include <map>

using namespace std;

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx)
{
	// int retval = stoi(ctx->CONST()->getText());
	return visitChildren(ctx);
}

antlrcpp::Any CodeGenVisitor::visitProgBegin(ifccParser::ProgBeginContext *ctx)
{
	cout << ".globl	_main\n"
			" _main: \n"
			"	pushq	%rbp\n"
			"	movq	%rsp, %rbp\n";
	return visitChildren(ctx);
}

antlrcpp::Any CodeGenVisitor::visitProgEnd(ifccParser::ProgEndContext *ctx)
{
	if (this->returnPresent) {
		cout << "   popq	%rbp\n"
				" 	ret\n";
	} else {
		cout 	<< 	"	xorl	%eax, %eax\n"
				<<	"   popq	%rbp\n"
				<<	" 	retq\n";
	}
	return visitChildren(ctx);
}



// antlrcpp::Any CodeGenVisitor::visitRetConst(ifccParser::RetConstContext *ctx)
// {
// 	int constantValue = stoi(ctx->CONST()->getText());
// 	cout << " 	movl	$" << constantValue << ", %eax\n";
// 	return visitChildren(ctx);
// }

antlrcpp::Any CodeGenVisitor::visitReturn(ifccParser::ReturnContext *ctx) {
	antlr4::tree::TerminalNode* variable = ctx->IDENTIFIER();
	antlr4::tree::TerminalNode* constant = ctx->CONST();
	this->returnPresent = true;
	if (variable != nullptr) {
		int variableAddress = (variableToMemoryMap[variable->getText()]) * -4;
		cout << " 	movl	" << variableAddress << "(%rbp), %eax\n";
	} else if (constant != nullptr) {
		int constantValue = stoi(constant->getText());
		cout << " 	movl	$" << constantValue << ", %eax\n";
	} else {
	}
	return visitChildren(ctx);
}


antlrcpp::Any CodeGenVisitor::visitDeclaration(ifccParser::DeclarationContext *ctx)
{
	std::vector<antlr4::tree::TerminalNode *> variables = ctx->IDENTIFIER();
	for (auto variable : variables)
	{
		if (variableToMemoryMap.find(variable->getText()) == variableToMemoryMap.end())
		{
			string variableName = variable->getText();
			variableToMemoryMap[variableName] = variableToMemoryMap.size() + 1;
		}
		else
		{
			// TODO throw an error
		}
	}
	return visitChildren(ctx);
}

antlrcpp::Any CodeGenVisitor::visitVarvar(ifccParser::VarvarContext *ctx)
{
	return visitChildren(ctx);
}

antlrcpp::Any CodeGenVisitor::visitVarconst(ifccParser::VarconstContext *ctx) {
	int constant = stoi(ctx->CONST()->getText());
	int variableAddress = -(variableToMemoryMap[ctx->IDENTIFIER()->getText()] * 4);
	cout << "	movl	$" << constant << ", " << variableAddress << "(%rbp) \n";
	return visitChildren(ctx);
}

// antlrcpp::Any CodeGenVisitor::visitDeclareVar(ifccParser::DeclareVarContext *ctx) {
// 	cout << "declare var";
//     return visitChildren(ctx);
//   }