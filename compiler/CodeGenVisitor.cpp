#include "CodeGenVisitor.h"
#include "antlr4-runtime.h"
#include "./generated/ifccVisitor.h"
#include <iostream>
#include <map>
#include <any>

using namespace std;

// {
// 	// int retval = stoi(ctx->CONST()->getText());
// 	return visitChildren(ctx);
// }

std::any CodeGenVisitor::visitProgBegin(ifccParser::ProgBeginContext *ctx)
{
	// detect and adapt for MAC_OS specificity
	string main = "main";

	#ifdef __APPLE__
		main = "_main";
	#endif

	cout << ".globl	" << main << "\n"
		 << main << ": \n"
					"	pushq	%rbp\n"
					"	movq	%rsp, %rbp\n";
	return visitChildren(ctx);
}

std::any CodeGenVisitor::visitProgEnd(ifccParser::ProgEndContext *ctx)
{
	if (this->returnPresent)
	{
		cout << "   popq	%rbp\n"
				" 	ret\n";
	}
	else
	{
		cout << "	xorl	%eax, %eax\n"
			 << "   popq	%rbp\n"
			 << " 	retq\n";
	}
	return visitChildren(ctx);
}

// std::any CodeGenVisitor::visitRetConst(ifccParser::RetConstContext *ctx)
// {
// 	int constantValue = stoi(ctx->CONST()->getText());
// 	cout << " 	movl	$" << constantValue << ", %eax\n";
// 	return visitChildren(ctx);
// }

std::any CodeGenVisitor::visitReturn(ifccParser::ReturnContext *ctx)
{
	antlr4::tree::TerminalNode *variable = ctx->IDENTIFIER();
	antlr4::tree::TerminalNode *constant = ctx->CONST();
	this->returnPresent = true;
	if (variable != nullptr)
	{

		if (variableToMemoryMap.find(variable->getText()) == variableToMemoryMap.end())
		{
			throw std::runtime_error("Variable " + variable->getText() + " not declared");
		}

		int variableAddress = (variableToMemoryMap[variable->getText()]) * -4;
		cout << " 	movl	" << variableAddress << "(%rbp), %eax\n";
	}
	else if (constant != nullptr)
	{
		int constantValue = stoi(constant->getText());
		cout << " 	movl	$" << constantValue << ", %eax\n";
	}
	else
	{
	}
	return visitChildren(ctx);
}

std::any CodeGenVisitor::visitDeclaration(ifccParser::DeclarationContext *ctx)
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

std::any CodeGenVisitor::visitAddmin(ifccParser::AddminContext *ctx)
{
	string oper = ctx->op->getText();
	string expr1VarName = any_cast<string>(visit(ctx->expr(0)));
	string expr2VarName = any_cast<string>(visit(ctx->expr(1)));

	int variable1Address = variableToMemoryMap[expr1VarName] * -4;
	int variable2Address = variableToMemoryMap[expr2VarName] * -4;
	cout << "	movl	" << variable1Address << "(%rbp), %eax \n";
	if (oper == "+")
	{ // Addition
		cout << "	addl	" << variable2Address << "(%rbp), %eax \n";
	}
	else
	{ // Subtraction
		cout << "	subl	" << variable2Address << "(%rbp), %eax \n";
	}

	string tempVariableName = "#tmp" + to_string(++this->nbTemporaryVariable);
	variableToMemoryMap[tempVariableName] = variableToMemoryMap.size() + 1;
	int tempVariableAddress = variableToMemoryMap[tempVariableName] * -4;
	cout << "	movl	%eax, " << tempVariableAddress << "(%rbp) \n";

	return tempVariableName;
}

std::any CodeGenVisitor::visitMultdiv(ifccParser::MultdivContext *ctx)
{
	string oper = ctx->op->getText();
	string expr1VarName = any_cast<string>(visit(ctx->expr(0)));
	string expr2VarName = any_cast<string>(visit(ctx->expr(1)));

	int variable1Address = variableToMemoryMap[expr1VarName] * -4;
	int variable2Address = variableToMemoryMap[expr2VarName] * -4;
	if (oper == "*")
	{ // Multiplication
		cout << "	imull	" << variable2Address << "(%rbp), %eax \n";
	}
	else
	{ // Division
		cout << "	idiv	" << variable2Address << "(%rbp), %eax \n";
	}

	string tempVariableName = "#tmp" + to_string(++this->nbTemporaryVariable);
	variableToMemoryMap[tempVariableName] = variableToMemoryMap.size() + 1;
	int tempVariableAddress = variableToMemoryMap[tempVariableName] * -4;
	cout << "	movl	%eax, " << tempVariableAddress << "(%rbp) \n";

	return tempVariableName;
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
	string temporaryVariableName = "#tmp" + to_string(this->nbTemporaryVariable);
	this->variableToMemoryMap[temporaryVariableName] = this->variableToMemoryMap.size() + 1;
	this->nbTemporaryVariable++;

	// Store constant in stack
	int variableAddress = this->variableToMemoryMap[temporaryVariableName] * -4;
	cout << "	movl	$" << number << ", " << variableAddress << "(%rbp) \n";

	return (string)temporaryVariableName;
}

std::any CodeGenVisitor::visitParenthesis(ifccParser::ParenthesisContext *ctx)
{
	return (string) "";
}

std::any CodeGenVisitor::visitUnaryMinus(ifccParser::UnaryMinusContext *ctx)
{
	return (string) "";
}

std::any CodeGenVisitor::visitAffectation(ifccParser::AffectationContext *ctx)
{
	string variableName = ctx->IDENTIFIER()->getText();
	string rValue = any_cast<string>(visit(ctx->expr()));

	int lValueAddress = variableToMemoryMap[variableName] * -4;
	int rValueAddress = variableToMemoryMap[rValue] * -4;

	cout << "	movl	" << rValueAddress << "(%rbp), %eax \n";
	cout << "	movl	%eax, " << lValueAddress << "(%rbp) \n";

	return 0;
}

// std::any CodeGenVisitor::visitVarvar(ifccParser::VarvarContext *ctx)
// {
// 	return visitChildren(ctx);
// }

// std::any CodeGenVisitor::visitVarconst(ifccParser::VarconstContext *ctx) {
// 	int constant = stoi(ctx->CONST()->getText());
// 	int variableAddress = -(variableToMemoryMap[ctx->IDENTIFIER()->getText()] * 4);
// 	cout << "	movl	$" << constant << ", " << variableAddress << "(%rbp) \n";
// 	return visitChildren(ctx);
// }

// std::any CodeGenVisitor::visitDeclareVar(ifccParser::DeclareVarContext *ctx) {
// 	cout << "declare var";
//     return visitChildren(ctx);
//   }