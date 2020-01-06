//
// Created by yuvalshechter on 05/01/2020.
//

#ifndef EX3_IFCOMMAND_H
#define EX3_IFCOMMAND_H


#include "symbolTables.h"
#include "ConditionParser.h"
/**
 * This class is deal with the if commands.
 * This class is part of command pattern.
 **/
class IfCommand: public ConditionParser {
private:
    vector<Command*> commands;
public:
    IfCommand(symbolTables* sT);
    int execute(int i);
    int setCommandsScope(int index);
};


#endif //EX3_IFCOMMAND_H
