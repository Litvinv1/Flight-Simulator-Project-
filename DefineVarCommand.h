//
// Created by yuvalshechter on 25/12/2019.
//

#ifndef EX3_DEFINEVARCOMMAND_H
#define EX3_DEFINEVARCOMMAND_H

#include "Command.h"
#include "lexer.h"
#include "simulatorFlightObject.h"
#include "symbolTables.h"
#include <unordered_map>
#include<stdio.h>
#include<ctype.h>
#include "ex1.h"
using namespace std;

extern  vector<string> vec;
//SPECIAL_OPERATORS

class DefineVarCommand : public Command{
private:
    symbolTables* st;
public:
    DefineVarCommand(symbolTables* sT);
    ~DefineVarCommand();
    virtual int execute(int index);
    //void print();

};

#endif //EX3_DEFINEVARCOMMAND_H
