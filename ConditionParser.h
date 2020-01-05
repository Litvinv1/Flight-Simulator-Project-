//
// Created by yuvalshechter on 03/01/2020.
//

#ifndef EX3_CONDITIONPARSER_H
#define EX3_CONDITIONPARSER_H
#include "string"
#include "simulatorFlightObject.h"
#include <unordered_map>
#include <functional>
#include "Command.h"
#include "symbolTables.h"

extern vector<string> vec;
extern unordered_map<string,Command*> cmdMap;
//template <typename OP>
//operator map
/*unordered_map<string, OP> opMap({
                                        {"==", std:: equal_to<>()},
                                        {"<=", std:: less_equal<>()},
                                        {">=", std:: greater_equal<>()},
                                        {"!=", std:: not_equal_to<>()},
                                        {"<",  std:: less<>()},
                                        {">",  std:: greater<>()}
                                });*/
class ConditionParser: public Command {


protected:
  symbolTables* st;
  vector<Command*> commands;
  vector<string> scopeVec;
  string varName;
  string op;
  float val;
public:
  ConditionParser();
  ConditionParser(symbolTables* sT);
  bool isSatisfied();
  int execute(int i);
  int setCommandsScope(int index);
  ~ConditionParser();
};


#endif //EX3_CONDITIONPARSER_H
