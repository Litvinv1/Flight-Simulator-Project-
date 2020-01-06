//
// Created by yuvalshechter on 22/12/2019.
//

#ifndef EX3_COMMAND_H
#define EX3_COMMAND_H
#include <vector>
#include <string>

using namespace std;

class Command {

public:
    virtual int execute(int i) = 0;
    virtual ~Command(){};
};


#endif //EX3_COMMAND_H
