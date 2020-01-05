//
// Created by yuvalshechter on 04/01/2020.
//

#include "LoopCommand.h"
#include <mutex>

LoopCommand::LoopCommand(symbolTables *sT){
  st = sT;
}

int LoopCommand::execute(int index) {
  mutex m;
  m.lock();
  varName = vec[index+1];
  op = vec[index+2];
  val = stof(vec[index+3]);
  int endScope = setCommandsScope(index);
  int j;
  while (isSatisfied()) {
    int n = index+6;
    for (j=0;j<commands.size();j++) {
     n = n + commands[j]->execute(j);
    }
  }
  m.unlock();
  return endScope;
}

LoopCommand::~LoopCommand() {}
