//
// Created by adam on 05/01/2020.
//

#ifndef EX_3_SYMBOLTABLES_H
#define EX_3_SYMBOLTABLES_H
#include "simulatorFlightObject.h"
#include <unordered_map>
using namespace std;

class symbolTables {
public:
  unordered_map<string, simulatorFlightObject*> rightSignToSimulator;
  unordered_map<string, simulatorFlightObject*> leftSignFromSimulator;

public:
  symbolTables();
  ~symbolTables();
};
#endif // EX_3_SYMBOLTABLES_H
