#include "CodeGenVisitor.h"
#include "antlr4-runtime.h"
#include "./generated/ifccVisitor.h"
#include <iostream>
#include <map>
#include <any>
#include "./models/Type.h"
#include "./IR/IR.h"

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

	string bbName = this->cfg.new_BB_name();
	BasicBlock* bb = new BasicBlock(&this->cfg, main);
	this->cfg.add_bb(bb);

	PrimitiveType* pt = PrimitiveType::getInstance();
	Type * voidType = pt->getType("void");

	bb->add_IRInstr(IRInstr::pushq, voidType, {"%bp"});
	bb->add_IRInstr(IRInstr::copy, voidType, {"%sp", "%bp"});

	// cout << ".globl	" << main << "\n"
	// 	 << main << ": \n"
	// 				"	pushq	%rbp\n"
	// 				"	movq	%rsp, %rbp\n";
	return visitChildren(ctx);
}

std::any CodeGenVisitor::visitProgEnd(ifccParser::ProgEndContext *ctx)
{
	BasicBlock * bb = new BasicBlock(&this->cfg, "end");
	this->cfg.add_bb(bb);

	PrimitiveType * pt = PrimitiveType::getInstance();
	Type * voidType = pt->getType("void");

	if (this->returnPresent)
	{
		bb->add_IRInstr(IRInstr::popq, voidType, {"%bp"});
		bb->add_IRInstr(IRInstr::ret, voidType, {});
		// cout << "   popq	%rbp\n"
		// 		" 	ret\n";
	}
	else
	{
		// bb->add_IRInstr(IRInstr::call, *voidType, {"_exit", "0"});
		bb->add_IRInstr(IRInstr::popq, voidType, {"%bp"});
		bb->add_IRInstr(IRInstr::retq, voidType, {});
		// cout << "	xorl	%eax, %eax\n"
		// 	 << "   popq	%rbp\n"
		// 	 << " 	retq\n";
	}
	return visitChildren(ctx);
}

std::any CodeGenVisitor::visitReturn(ifccParser::ReturnContext *ctx)
{

	string exprVarName = any_cast<string>(visit(ctx->expr()));

	if (variableToMemoryMap.find(exprVarName) == variableToMemoryMap.end())
	{
		throw std::runtime_error("Variable " + exprVarName + " not declared");
	}

	int variableAddress = variableToMemoryMap[exprVarName] * -4;
	this->returnPresent = true;

	cout << " 	movl	" << variableAddress << "(%rbp), %eax		# move " << exprVarName << " to eax for return \n";

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
	cout << "	movl	" << variable1Address << "(%rbp), %eax 		# move " << expr1VarName << " to eax \n";
	if (oper == "+")
	{ // Addition
		cout << "	addl	" << variable2Address << "(%rbp), %eax		# addition \n";
	}
	else
	{ // Subtraction
		cout << "	subl	" << variable2Address << "(%rbp), %eax		# substraction \n";
	}

	string tempVariableName = "#tmp" + to_string(variableToMemoryMap.size() + 1);
	variableToMemoryMap[tempVariableName] = variableToMemoryMap.size() + 1;
	int tempVariableAddress = variableToMemoryMap[tempVariableName] * -4;
	cout << "	movl	%eax, " << tempVariableAddress << "(%rbp) 		# store expression result in temporary space in the stack \n";

	return tempVariableName;
}

std::any CodeGenVisitor::visitMultdiv(ifccParser::MultdivContext *ctx)
{
	string oper = ctx->op->getText();
	string expr1VarName = any_cast<string>(visit(ctx->expr(0)));
	string expr2VarName = any_cast<string>(visit(ctx->expr(1)));

	int variable1Address = variableToMemoryMap[expr1VarName] * -4;
	int variable2Address = variableToMemoryMap[expr2VarName] * -4;
	cout << "	movl	" << variable1Address << "(%rbp), %eax		# move operand 1 to eax \n";
	if (oper == "*")
	{ // Multiplication
		cout << "	imull	" << variable2Address << "(%rbp), %eax		# apply multiplication \n";
	}
	else
	{ // Division
		cout << "	cltd			# initialize sign register \n";
		cout << "	idivl	" << variable2Address << "(%rbp)		# apply division \n";
	}

	string tempVariableName = "#tmp" + to_string(variableToMemoryMap.size() + 1);
	variableToMemoryMap[tempVariableName] = variableToMemoryMap.size() + 1;
	int tempVariableAddress = variableToMemoryMap[tempVariableName] * -4;
	cout << "	movl	%eax, " << tempVariableAddress << "(%rbp) # store expression result in temporary space in the stack \n";

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
	string temporaryVariableName = "#tmp" + to_string(variableToMemoryMap.size() + 1);
	this->variableToMemoryMap[temporaryVariableName] = this->variableToMemoryMap.size() + 1;
	this->nbTemporaryVariable++;

	// Store constant in stack
	int variableAddress = this->variableToMemoryMap[temporaryVariableName] * -4;
	cout << "	movl	$" << number << ", " << variableAddress << "(%rbp) 	# Store constant in " << temporaryVariableName << " \n";

	return (string)temporaryVariableName;
}

std::any CodeGenVisitor::visitParenthesis(ifccParser::ParenthesisContext *ctx)
{
	return any_cast<string>(visit(ctx->expr()));
}

std::any CodeGenVisitor::visitUnaryExpression(ifccParser::UnaryExpressionContext *ctx) {
	string oper = ctx->op->getText();

	string exprVarName = any_cast<string>(visit(ctx->expr()));
	int variableAddress = variableToMemoryMap[exprVarName] * -4;

	if (oper == "-") {

		// Apply minus
		cout << "	xorl 	%eax, %eax		# reset eax \n";
		cout << "	subl	" << variableAddress << "(%rbp), %eax		# apply minus \n";

		// Temporary space in stack
		string tempVariableName = "#tmp" + to_string(variableToMemoryMap.size() + 1);
		variableToMemoryMap[tempVariableName] = variableToMemoryMap.size() + 1;
		int tempVariableAddress = variableToMemoryMap[tempVariableName] * -4;

		// Store result in temporary space in stack
		cout << "	movl	%eax, " << tempVariableAddress << "(%rbp)		# store result in temporary space in stack \n";

		return (string) tempVariableName;

	} else {
		return exprVarName;
	}
}


std::any CodeGenVisitor::visitAffectation(ifccParser::AffectationContext *ctx)
{
	string variableName = ctx->IDENTIFIER()->getText();
	string rValueVariableName = any_cast<string>(visit(ctx->expr()));

	int lValueAddress = variableToMemoryMap[variableName] * -4;
	int rValueAddress = variableToMemoryMap[rValueVariableName] * -4;

	cout << "	movl	" << rValueAddress << "(%rbp), %eax		# retrieve value from temporary space in stack \n";
	cout << "	movl	%eax, " << lValueAddress << "(%rbp)		# affect to " << variableName << "\n";

	return 0;
}