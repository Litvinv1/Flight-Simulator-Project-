//
// Created by yuvalshechter on 03/01/2020.
//

#ifndef EX3_SLEEPCOMMAND_H
#define EX3_SLEEPCOMMAND_H

#include "Command.h"
#include "symbolTables.h"
#include <iostream>
using namespace std;

extern vector<string>vec;
/**
 * This class deal with the command from type sleep and calculate the number of time to wait.
 * return the number of the steps to get other sleep command.
 * This class is part of command pattern.
 **/
class SleepCommand : public Command{
private:
    symbolTables *st;
public:
    SleepCommand(symbolTables* sT);
    ~SleepCommand();
    virtual int execute(int i);

};


#endif //EX3_SLEEPCOMMAND_H
