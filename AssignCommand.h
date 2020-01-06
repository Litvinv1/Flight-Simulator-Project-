//
// Created by adam on 02/01/2020.
//
#include "Command.h"
#include "simulatorFlightObject.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <set>
using namespace std;
#ifndef EX_3_ASSIGNCOMMAND_H
#define EX_3_ASSIGNCOMMAND_H
#include "symbolTables.h"
using namespace std;
extern int cs;
extern vector<string>vec;

/**
 * This calls deal the variables with assign action and update in the map the new value of those variables.
 * return the number of the steps to get other assign command.
 * This class is part of command pattern.
 **/
class AssignCommand:public Command {
private:
    set<string> MATH_OPERATORS = {"-", "+", "*", "/"};
    symbolTables* st;

public:
    AssignCommand(symbolTables* st);
    ~AssignCommand();
    virtual int execute(int i);
    bool is_number(const string &s);
};

#endif // EX_3_ASSIGNCOMMAND_H