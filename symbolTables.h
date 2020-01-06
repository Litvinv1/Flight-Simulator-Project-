//
// Created by yuvalshechter on 05/01/2020.
//

#ifndef EX3_SYMBOLTABLES_H
#define EX3_SYMBOLTABLES_H
#include "string"
#include "simulatorFlightObject.h"
#include <unordered_map>
class symbolTables {
public:
    unordered_map<string, simulatorFlightObject*> rightSignToSimulator;
    unordered_map<string, simulatorFlightObject*> leftSignFromSimulator;
public:
    symbolTables();
};


#endif //EX3_SYMBOLTABLES_H
