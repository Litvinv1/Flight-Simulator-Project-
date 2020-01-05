//
// Created by yuvalshechter on 22/12/2019.
//

#ifndef EX3_COMMAND_H
#define EX3_COMMAND_H
#include <vector>
#include <string>
using namespace std;

/**
 * This class is interface that every other command are inherit from it.
 * This class is contain the function execute that return the number of the steps to the next command.
 */
class Command {

public:
  virtual int execute(int i) = 0;
  virtual ~Command(){};
};


#endif //EX3_COMMAND_H
