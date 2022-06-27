#pragma once

#include <string>
#include <map>

using namespace std;

class Type {
private :
    string name;    // The name of the type
    int size;       // Size in bytes

public :
    Type(string name, int size) : name(name), size(size) {}

    string getName() { return name; }
    int getSize() { return size; }
};




class PrimitiveType: public Type {
private :
    inline static PrimitiveType* _instance = nullptr;

    map<string, Type*> types;

    PrimitiveType(string name, int size) : Type(name, size) {}


public :
    PrimitiveType(PrimitiveType &other) = delete;

    void operator=(const PrimitiveType &) = delete;

    static PrimitiveType* getInstance() {
        if (PrimitiveType::_instance == nullptr) {
            _instance = new PrimitiveType("PrimitiveType", 0);
            _instance->types["int"] = new Type("int", 4);
            _instance->types["float"] = new Type("float", 4);
            _instance->types["double"] = new Type("double", 8);
            _instance->types["void"] = new Type("void", 0);
            _instance->types["bool"] = new Type("bool", 1);
        }
        return PrimitiveType::_instance;
    }

    Type* getType(string name) {
        Type * type = this->types[name];
        if (type == nullptr) {
            throw "Type " + name + " not found"; 
        }
        return type;
    }

};