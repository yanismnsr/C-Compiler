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
	Symbol(int memAdd, bool used): memoryAddress(memAdd), isUsed(used) {}
} Symbol;

class SymbolList {
private:
    static SymbolList* symbolListInstance;
	SymbolList();
	void operator=(const SymbolList& otherSymbolList) = delete;
    SymbolList(const SymbolList& symbolList) = delete;

	map<string, Symbol*> variableToMemoryMap;
	void writeWarning(string message);
	ofstream warningsFile;
public:
	static SymbolList* getInstance();
	Symbol& addVariable(string address);
	Symbol* getSymbol(string variableName);
};

