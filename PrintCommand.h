//
// Created by adam on 02/01/2020.
//

#ifndef EX_3_PRINTCOMMAND_H
#define EX_3_PRINTCOMMAND_H
#include"Command.h"
#include "simulatorFlightObject.h"
#include "symbolTables.h"
#include <iomanip>
#include <iostream>
#include <unordered_map>
using namespace std;
extern bool flag;
extern vector<string>vec;

/**
 * This class deal with the command from type print and print the value of the variable that he hold.
 * return the number of the steps to get other print command.
 * This class is part of command pattern.
 **/
class PrintCommand : public Command{
private:
    symbolTables* st;
public:
    PrintCommand(symbolTables* sT);
    ~PrintCommand();
    virtual int execute(int i);

};

#endif // EX_3_PRINTCOMMAND_H