#include <iostream>
#include <map>


#include "./SymbolList.h"

using namespace std;

SymbolList* SymbolList::symbolListInstance = nullptr;

SymbolList::SymbolList() {}

void SymbolList::writeWarning(string message)
{
	warningsFile.open(WARNING_FILE_RELATIVE_PATH);
	warningsFile << message << endl;
	warningsFile.close();
}

Symbol& SymbolList::addVariable(string variableName)
{
	if (variableToMemoryMap.find(variableName) == variableToMemoryMap.end())
	{
		variableToMemoryMap[variableName] = new Symbol((variableToMemoryMap.size() + 1) * -4, false, variableName);
	}
	else
	{
		cerr << "Variable \'" + variableName + "\' already exists." << endl;
		hasError = true;
	}

	return *(variableToMemoryMap[variableName]);
}

Symbol& SymbolList::addTemporaryVariable()
{
	string temporaryVariableName = "#tmp" + to_string(++nbTemporaryVariables);
	variableToMemoryMap[temporaryVariableName] = new Symbol((variableToMemoryMap.size() + 1) * -4, false, temporaryVariableName);
	return *(variableToMemoryMap[temporaryVariableName]);
}

Symbol* SymbolList::getSymbol(string variableName)
{
	Symbol* symbol = variableToMemoryMap.find(variableName) == variableToMemoryMap.end() ? nullptr : variableToMemoryMap.find(variableName)->second;
	if (symbol == nullptr) 
	{
		cerr << "Variable \'" + variableName + "\' was not declared" << endl;
		hasError = true;
	}
	return symbol;
}

bool SymbolList::getHasError() { return hasError; }


SymbolList* SymbolList::getInstance()
{
       if (symbolListInstance == nullptr)
           symbolListInstance = new SymbolList(); 
      
        return symbolListInstance;
}
