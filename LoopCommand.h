//
// Created by yuvalshechter on 04/01/2020.
//

#ifndef EX3_LOOPCOMMAND_H
#define EX3_LOOPCOMMAND_H


#include "ConditionParser.h"
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
    vector<Command*> commands;
public:
    LoopCommand(symbolTables* sT);
    int execute(int i);

    int setCommandsScope(int index);
};


#endif //EX3_LOOPCOMMAND_H
