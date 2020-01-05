//
// Created by yuvalshechter on 04/01/2020.
//

#ifndef EX3_LOOPCOMMAND_H
#define EX3_LOOPCOMMAND_H


#include "ConditionParser.h"
#include "symbolTables.h"
#include <functional>
using namespace std;
extern vector<string>vec;

/**
 * This class is deal with the while commands.
 * LoopCommand return the...
 * This class is part of command pattern.
 **/
class LoopCommand: public ConditionParser {
private:
  symbolTables *st;

public:
  LoopCommand(symbolTables *sT);
  ~LoopCommand();
  int execute(int index);
};


#endif //EX3_LOOPCOMMAND_H
