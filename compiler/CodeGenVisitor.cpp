#include "CodeGenVisitor.h"
#include "antlr4-runtime.h"
#include "./generated/ifccVisitor.h"
#include "./SymbolList.h"
#include <iostream>
#include <map>
#include <any>

using namespace std;

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

	SymbolList::getInstance()->checkAreAllDeclaredVariablesUsedAndInitialized();
	if (SymbolList::getInstance()->getHasError()) 
	{
		throw std::runtime_error("");
	}
	return visitChildren(ctx);
}

std::any CodeGenVisitor::visitReturn(ifccParser::ReturnContext *ctx)
{
	string exprVarName = any_cast<string>(visit(ctx->expr()));
	Symbol* symbol = SymbolList::getInstance()->getSymbol(exprVarName);
	this->returnPresent = true;
	if (symbol != nullptr)
	{
		int variableAddress = SymbolList::getInstance()->getSymbol(exprVarName)->memoryAddress;
		cout << " 	movl	" << symbol->memoryAddress << "(%rbp), %eax\n";
	}
	return visitChildren(ctx);
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
	Symbol* variable1 = SymbolList::getInstance()->getSymbol(expr1VarName);
	Symbol* variable2 = SymbolList::getInstance()->getSymbol(expr2VarName);
	
	if (variable1 != nullptr)
	{
		cout << "	movl	" << variable1->memoryAddress << "(%rbp), %eax \n";
	}
	if (variable2 != nullptr)
	{
		if (oper == "+")
		{ // Addition
			cout << "	addl	" << variable2->memoryAddress << "(%rbp), %eax \n";
		}
		else
		{ // Subtraction
			cout << "	subl	" << variable2->memoryAddress << "(%rbp), %eax \n";
		}
	}
	Symbol temporarySymbolAdded = SymbolList::getInstance()->addTemporaryVariable();
	cout << "	movl	%eax, " << temporarySymbolAdded.memoryAddress << "(%rbp) \n";

	return temporarySymbolAdded.symbolName;
}

std::any CodeGenVisitor::visitMultdiv(ifccParser::MultdivContext *ctx)
{
	string oper = ctx->op->getText();
	string expr1VarName = any_cast<string>(visit(ctx->expr(0)));
	string expr2VarName = any_cast<string>(visit(ctx->expr(1)));
	Symbol* variable1 = SymbolList::getInstance()->getSymbol(expr1VarName);
	Symbol* variable2 = SymbolList::getInstance()->getSymbol(expr2VarName);

	if (variable1 != nullptr)
	{
		cout << "	movl	" << variable1->memoryAddress << "(%rbp), %eax		# move operand 1 to eax \n";
	}
	if (variable2 != nullptr)
	{
		if (oper == "*")
		{ // Multiplication
			cout << "	imull	" << variable2->memoryAddress << "(%rbp), %eax		# apply multiplication \n";
		}
		else
		{ // Division
			cout << "	cltd			# initialize sign register \n";
			cout << "	idivl	" << variable2->memoryAddress << "(%rbp)		# apply division \n";
		}
	}
	Symbol temporarySymbolAdded = SymbolList::getInstance()->addTemporaryVariable();
	cout << "	movl	%eax, " << temporarySymbolAdded.memoryAddress << "(%rbp) # store expression result in temporary space in the stack \n";

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

	// Store constant in stack
	cout << "	movl	$" << number << ", " << temporarySymbolAdded.memoryAddress << "(%rbp) 	# Store constant in " << temporarySymbolAdded.memoryAddress << " \n";

	return (string)temporarySymbolAdded.symbolName;
}

std::any CodeGenVisitor::visitParenthesis(ifccParser::ParenthesisContext *ctx)
{
	return any_cast<string>(visit(ctx->expr()));
}

std::any CodeGenVisitor::visitUnaryExpression(ifccParser::UnaryExpressionContext *ctx) {
	string oper = ctx->op->getText();

	string exprVarName = any_cast<string>(visit(ctx->expr()));
	Symbol* variable1 = SymbolList::getInstance()->getSymbol(exprVarName);

	int variableAddress = variableToMemoryMap[exprVarName] * -4;

	if (oper == "-") {

		// Apply minus
		cout << "	xorl 	%eax, %eax		# reset eax \n";
		if (variable1 != nullptr) 
		{
			cout << "	subl	" << variable1->memoryAddress << "(%rbp), %eax		# apply minus \n";
		}
		// Temporary space in stack
		Symbol temporarySymbolAdded = SymbolList::getInstance()->addTemporaryVariable();

		// Store result in temporary space in stack
		cout << "	movl	%eax, " << temporarySymbolAdded.memoryAddress << "(%rbp)		# store result in temporary space in stack \n";

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

	int lValueAddress = SymbolList::getInstance()->getSymbol(variableName)->memoryAddress;
	int rValueAddress = SymbolList::getInstance()->getSymbol(rValueVariableName)->memoryAddress;

	cout << "	movl	" << rValueAddress << "(%rbp), %eax		# retrieve value from temporary space in stack \n";
	cout << "	movl	%eax, " << lValueAddress << "(%rbp)		# affect to " << variableName << "\n";
	SymbolList::getInstance()->setVariableIsInitialized(variableName, true);

	return 0;
}