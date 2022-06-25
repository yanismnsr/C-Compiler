#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

#include "antlr4-runtime.h"
#include "generated/ifccLexer.h"
#include "generated/ifccParser.h"
#include "generated/ifccBaseVisitor.h"

#include "CodeGenVisitor.h"

#include "./Backend/X86Strategy.h"
#include "./Backend/ARMStrategy.h"
#include "./Backend/BackendStrategy.h"

using namespace antlr4;
using namespace std;

int main(int argn, const char **argv)
{
    stringstream in;

    string targetArchitecture = "x86";
    BackendStrategy *backendStrategy = nullptr;

    if (argn >= 2)
    {
        ifstream lecture(argv[1]);
        in << lecture.rdbuf();

        if (argn >= 3)
        {
            targetArchitecture = argv[2];
            if (targetArchitecture != "x86" && targetArchitecture != "arm")
            {
                cerr << "Invalid architecture" << endl;
                cerr << "Supported architectures : arm, x86" << endl;
                exit(1);
            }
        }
    }
    else
    {
        cerr << "usage: ifcc path/to/file.c [targetArchitecture]" << endl;
        cerr << "Supported architectures : arm, x86" << endl;
        exit(1);
    }

    ANTLRInputStream input(in.str());

    ifccLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    tokens.fill();

    ifccParser parser(&tokens);
    tree::ParseTree *tree = parser.axiom();

    if (parser.getNumberOfSyntaxErrors() != 0)
    {
        cerr << "error: syntax error during parsing" << endl;
        exit(1);
    }

    if (targetArchitecture == "x86")
    {
        backendStrategy = new X86Strategy();
    }
    else if (targetArchitecture == "arm")
    {
        backendStrategy = new ARMStrategy();
    }

    CodeGenVisitor v(backendStrategy);
    v.visit(tree);
    v.getCFG().gen_asm(cout);

	
    SymbolTable * symbolTable = v.getCFG().current_bb->symbolTable;
    CFG cfg = v.getCFG();
	for (auto block : cfg.bbs)
	{
		block->symbolTable->checkAreAllDeclaredVariablesUsedAndInitialized();
	}
    if (v.getCFG().getHasError())
    {
        throw std::runtime_error("");
    }

    return 0;
}
