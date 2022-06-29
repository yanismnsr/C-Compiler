#pragma once

#include <map>
#include <string>
#include <fstream> // std::ifstream

#include "./IR/IR.h"

using namespace std;

const string WARNING_FILE_RELATIVE_PATH = "warnings.txt";

class BasicBlock;

typedef struct Symbol
{
    int memoryAddress;
	bool isTemporary;
	bool isUsed;
	bool isInitialized;
	string symbolName;
	Symbol(int memAdd, bool used, bool temporary, bool initialized, string name = ""): memoryAddress(memAdd), isUsed(used), isInitialized(initialized), isTemporary(temporary), symbolName(name) {}
} Symbol;

class SymbolTable {
private:
	map<string, Symbol*> variableToMemoryMap;
	int nbTemporaryVariables = 0;
	bool hasError = false;
	ofstream warningsFile;

	SymbolTable * parentSymbolTable;
	BasicBlock * basicBlock;

	int memoryOffset;

	void writeWarning(string message);
	void cleanWarningsFile();
public:
	SymbolTable(BasicBlock* bb);
	SymbolTable(BasicBlock* bb, SymbolTable* parentSymbolTable);
	Symbol& addVariable(string variableName);
	Symbol& addTemporaryVariable();
	Symbol* getSymbol(string variableName);
	bool getHasError();
	void checkAreAllDeclaredVariablesUsedAndInitialized();
	void setVariableIsInitialized(string variableName, bool isInitialized);
	int getNextAllowedAddress();

	int getAddress(string variableName);

	int getSize();
};

