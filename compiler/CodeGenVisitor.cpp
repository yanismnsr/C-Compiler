#include "CodeGenVisitor.h"

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) 
{
	int retval = stoi(ctx->CONST()->getText());
	std::cout<<".globl	_main\n"
		" _main: \n"
		"	pushq	%rbp\n"
		"	movq	%rsp, %rbp\n"
		" 	movl	$"<<retval<<", %eax\n"
		"   popq	%rbp\n"
		" 	ret\n";

	return 0;
}

