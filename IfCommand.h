//
// Created by adam on 05/01/2020.
//

#ifndef EX_3_IFCOMMAND_H
#define EX_3_IFCOMMAND_H


#include "ConditionParser.h"
#include "symbolTables.h"
using namespace std;
extern vector<string>vec;

/**
 * This class is deal with the if commands.
 * This class is part of command pattern.
 **/
class IfCommand : public ConditionParser {
private:
  symbolTables *st;

public:
  IfCommand(symbolTables *sT);
  ~IfCommand();
  virtual int execute(int index);
};

#endif // EX_3_IFCOMMAND_H
