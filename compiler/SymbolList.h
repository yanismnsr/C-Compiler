#pragma once

#include <map>
#include <string>
#include <fstream> // std::ifstream

using namespace std;

const string WARNING_FILE_RELATIVE_PATH = "warnings.txt";

typedef struct Symbol
{
    int memoryAddress;
	bool isUsed;
	string symbolName;
	Symbol(int memAdd, bool used, string name = ""): memoryAddress(memAdd), isUsed(used), symbolName(name) {}
} Symbol;

class SymbolList {
private:
    static SymbolList* symbolListInstance;
	SymbolList();
	void operator=(const SymbolList& otherSymbolList) = delete;
    SymbolList(const SymbolList& symbolList) = delete;

	map<string, Symbol*> variableToMemoryMap;
	int nbTemporaryVariables = 0;
	bool hasError = false;
	ofstream warningsFile;

	void writeWarning(string message);
	void cleanWarningsFile();
public:
	static SymbolList* getInstance();
	Symbol& addVariable(string address);
	Symbol& addTemporaryVariable();
	Symbol* getSymbol(string variableName);
	bool getHasError();
	void checkAreAllDeclaredVariablesAreUsed();
};

