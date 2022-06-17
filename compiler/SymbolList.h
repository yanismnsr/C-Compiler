#pragma once

#include <map>
#include <string>
#include <fstream> // std::ifstream

using namespace std;

const string WARNING_FILE_RELATIVE_PATH = "warnings.txt";

typedef struct Symbol
{
    int memoryAddress;
	bool isTemporary;
	bool isUsed;
	bool isInitialized;
	string symbolName;
	Symbol(int memAdd, bool used, bool temporary, bool initialized, string name = ""): memoryAddress(memAdd), isUsed(used), isInitialized(initialized), isTemporary(temporary), symbolName(name) {}
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
	void checkAreAllDeclaredVariablesUsedAndInitialized();
	void setVariableIsInitialized(string variableName, bool isInitialized);
};

