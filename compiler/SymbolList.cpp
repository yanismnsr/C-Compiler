#include <iostream>
#include <map>


#include "./SymbolList.h"

using namespace std;

SymbolList* SymbolList::symbolListInstance = nullptr;

SymbolList::SymbolList() 
{
	cleanWarningsFile();
}

void SymbolList::cleanWarningsFile()
{
	warningsFile.open(WARNING_FILE_RELATIVE_PATH);
	warningsFile << "";
	warningsFile.close();
}

void SymbolList::writeWarning(string message)
{
	warningsFile.open(WARNING_FILE_RELATIVE_PATH, std::ios_base::app);
	warningsFile << message << endl;
	warningsFile.close();
}

Symbol& SymbolList::addVariable(string variableName)
{
	if (variableToMemoryMap.find(variableName) == variableToMemoryMap.end())
	{
		variableToMemoryMap[variableName] = new Symbol((variableToMemoryMap.size() + 1) * -4, false, false, false, variableName);
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
	variableToMemoryMap[temporaryVariableName] = new Symbol((variableToMemoryMap.size() + 1) * -4, true, true, true, temporaryVariableName);
	return *(variableToMemoryMap[temporaryVariableName]);
}

Symbol* SymbolList::getSymbol(string variableName)
{
	Symbol* symbol = variableToMemoryMap.find(variableName) == variableToMemoryMap.end() ? nullptr : variableToMemoryMap.find(variableName)->second;
	if (symbol == nullptr) 
	{
		cerr << "Variable \'" + variableName + "\' was not declared" << endl;
		hasError = true;
	} else 
	{
		symbol->isUsed = true;
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

void SymbolList::checkAreAllDeclaredVariablesUsedAndInitialized()
{
	for (auto variable : variableToMemoryMap)
	{
		if (!variable.second->isTemporary)
		{
			if (!variable.second->isUsed) 
			{
				writeWarning("Variable \'" + variable.first + "\' is declared but never used.\n");
			}
			if (!variable.second->isInitialized) 
			{
				writeWarning("Variable \'" + variable.first + "\' is not initialized.\n");
			}
		}
	}
}

void SymbolList::setVariableIsInitialized(string variableName, bool isInitialized) 
{
	Symbol* symbol = variableToMemoryMap.find(variableName) == variableToMemoryMap.end() ? nullptr : variableToMemoryMap.find(variableName)->second;
	if (symbol != nullptr) 
	{
		variableToMemoryMap.find(variableName)->second->isInitialized = isInitialized;
	}
}


