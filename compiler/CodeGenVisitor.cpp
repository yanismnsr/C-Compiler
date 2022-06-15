#include "CodeGenVisitor.h"
#include "antlr4-runtime.h"
#include "./generated/ifccVisitor.h"
#include "./SymbolList.h"
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

	//TODO check les variables used --> mais à mettre apres le visitChildren 
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
		if (SymbolList::getInstance()->getSymbol(variable->getText()) == nullptr)
		{
			throw std::runtime_error("Variable " + variable->getText() + " not declared");
		}

		int variableAddress = SymbolList::getInstance()->getSymbol(variable->getText())->memoryAddress;
		cout << " 	movl	" << SymbolList::getInstance()->getSymbol(variable->getText())->memoryAddress << "(%rbp), %eax\n";
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
		string variableName = variable->getText();
/* 		if (variableToMemoryMap.find(variable->getText()) == variableToMemoryMap.end())
		{
			variableToMemoryMap[variableName] = variableToMemoryMap.size() + 1;
		}
		else
		{
				writeWarning("Variable " + variableName + " already exists.");
		} */
		SymbolList::getInstance()->addVariable(variableName);
	}
	return visitChildren(ctx);
}

std::any CodeGenVisitor::visitAddmin(ifccParser::AddminContext *ctx)
{
	string oper = ctx->op->getText();
	string expr1VarName = any_cast<string>(visit(ctx->expr(0)));
	string expr2VarName = any_cast<string>(visit(ctx->expr(1)));

//	int variable1Address = variableToMemoryMap[expr1VarName] * -4;
//	int variable2Address = variableToMemoryMap[expr2VarName] * -4;
//TODO gérer si variable n'est pas déclarée !!!!!!!!!!!!!!
	cout << "	movl	" << SymbolList::getInstance()->getSymbol(expr1VarName)->memoryAddress << "(%rbp), %eax \n";
	if (oper == "+")
	{ // Addition
		cout << "	addl	" << SymbolList::getInstance()->getSymbol(expr2VarName)->memoryAddress << "(%rbp), %eax \n";
	}
	else
	{ // Subtraction
		cout << "	subl	" << SymbolList::getInstance()->getSymbol(expr2VarName)->memoryAddress << "(%rbp), %eax \n";
	}

	//variableToMemoryMap[tempVariableName] = variableToMemoryMap.size() + 1;
	Symbol symbolAdded = SymbolList::getInstance()->addTemporaryVariable();
	//int tempVariableAddress = variableToMemoryMap[tempVariableName] * -4;
	cout << "	movl	%eax, " << symbolAdded.memoryAddress << "(%rbp) \n";


	return symbolAdded.symbolName;
}

std::any CodeGenVisitor::visitMultdiv(ifccParser::MultdivContext *ctx)
{
	string oper = ctx->op->getText();
	string expr1VarName = any_cast<string>(visit(ctx->expr(0)));
	string expr2VarName = any_cast<string>(visit(ctx->expr(1)));

//TODO gérer si variable n'est pas déclarée !!!!!!!!!!!!!!
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

		Symbol symbolAdded = SymbolList::getInstance()->addTemporaryVariable();

	cout << "	movl	%eax, " << symbolAdded.memoryAddress << "(%rbp) \n";

	return symbolAdded.symbolName;
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
	Symbol symbolAdded = SymbolList::getInstance()->addTemporaryVariable();

	// Store constant in stack
	cout << "	movl	$" << number << ", " << symbolAdded.memoryAddress << "(%rbp) \n";

	return (string)symbolAdded.symbolName;
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

	int lValueAddress = SymbolList::getInstance()->getSymbol(variableName)->memoryAddress;
	int rValueAddress = SymbolList::getInstance()->getSymbol(rValue)->memoryAddress;

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