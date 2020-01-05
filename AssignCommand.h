//
// Created by adam on 02/01/2020.
//
#ifndef EX_3_ASSIGNCOMMAND_H
#define EX_3_ASSIGNCOMMAND_H


#include "Command.h"
#include "simulatorFlightObject.h"
#include "symbolTables.h"
#include "ConnectCommand.h"
#include <string>
#include <unordered_map>
using namespace std;
extern int cs;
extern vector<string>vec;
extern unordered_map<string, simulatorFlightObject*> rightSignToSimulator;
extern unordered_map<string, simulatorFlightObject*> leftSignFromSimulator;

/**
 * This calls deal the variables with assign action and update in the map the new value of those variables.
 * return the number of the steps to get other assign command.
 * This class is part of command pattern.
 **/
class AssignCommand:public Command {
private:
  symbolTables *st;
public:
  AssignCommand(symbolTables *sT);
  ~AssignCommand();
  virtual int execute(int i);
  //virtual int returnJumps(int i);
};

#endif // EX_3_ASSIGNCOMMAND_H
