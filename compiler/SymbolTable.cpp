#include <iostream>
#include <map>


#include "./SymbolTable.h"

using namespace std;

SymbolTable::SymbolTable(BasicBlock* bb) 
{
	cleanWarningsFile();
	this->basicBlock = bb; 
	this->parentSymbolTable = nullptr;
}

SymbolTable::SymbolTable(BasicBlock* bb, SymbolTable* parentSymbolTable) {
	cleanWarningsFile();
	this->basicBlock = bb;
	this->parentSymbolTable = parentSymbolTable;
}

void SymbolTable::cleanWarningsFile()
{
	warningsFile.open(WARNING_FILE_RELATIVE_PATH);
	warningsFile << "";
	warningsFile.close();
}

void SymbolTable::writeWarning(string message)
{
	warningsFile.open(WARNING_FILE_RELATIVE_PATH, std::ios_base::app);
	warningsFile << message << endl;
	warningsFile.close();
}

Symbol& SymbolTable::addVariable(string variableName)
{
	if (variableToMemoryMap.find(variableName) == variableToMemoryMap.end())
	{
		variableToMemoryMap[variableName] = new Symbol((variableToMemoryMap.size() + 1) * -4, false, false, false, variableName);
	}
	else
	{
		cerr << "Variable \'" + variableName + "\' already exists." << endl;
		this->basicBlock->cfg->errorFound();
	}

	return *(variableToMemoryMap[variableName]);
}

Symbol& SymbolTable::addTemporaryVariable()
{
	string temporaryVariableName = "#tmp" + to_string(++nbTemporaryVariables);
	variableToMemoryMap[temporaryVariableName] = new Symbol((variableToMemoryMap.size() + 1) * -4, true, true, true, temporaryVariableName);
	return *(variableToMemoryMap[temporaryVariableName]);
}

Symbol* SymbolTable::getSymbol(string variableName)
{
	bool found = false;
	SymbolTable * st = this;
	Symbol* symbol;

	while (st != nullptr) {
		symbol = variableToMemoryMap.find(variableName) == variableToMemoryMap.end() ? nullptr : variableToMemoryMap.find(variableName)->second;
		if (symbol != nullptr) {
			found = true;
			symbol->isUsed = true;
			return symbol;
		}
		st = st->parentSymbolTable;
	}

	if (!found) 
	{
		cerr << "Variable \'" + variableName + "\' was not declared" << endl;
		this->basicBlock->cfg->errorFound();
	}
	return nullptr;
}

bool SymbolTable::getHasError() { return hasError; }


void SymbolTable::checkAreAllDeclaredVariablesUsedAndInitialized()
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

void SymbolTable::setVariableIsInitialized(string variableName, bool isInitialized) 
{
	Symbol* symbol = variableToMemoryMap.find(variableName) == variableToMemoryMap.end() ? nullptr : variableToMemoryMap.find(variableName)->second;
	if (symbol != nullptr) 
	{
		variableToMemoryMap.find(variableName)->second->isInitialized = isInitialized;
	}
}


