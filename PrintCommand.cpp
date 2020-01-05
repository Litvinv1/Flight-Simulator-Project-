//
// Created by yuvalshechter on 02/01/2020.
//

#include "PrintCommand.h"
#include <iostream>
#include <mutex>

using namespace std;

PrintCommand::PrintCommand(symbolTables *sT){
  st = sT;
}

int PrintCommand::execute(int index) {
  mutex m;
  m.lock();
  // toPrint is a print command that we should print
  string toPrint = vec[index+2];
  //if there is quotation marks we should print without it
  if(toPrint[0] == '"') {
    //cut the quotation marks
    toPrint = toPrint.substr(1, toPrint.length() - 2);
    //print the command
    cout << toPrint << endl;
    //it's not a print command and we need to print the value of the variable
  } else {
    //check if the variable is exist in the rightSignToSimulator map and print the value
    if(st->rightSignToSimulator[toPrint]){
      cout << st->rightSignToSimulator[toPrint]->getValue();
      //the variable is exist in the leftSignFromSimulator map and print the value
    } else if (st->leftSignFromSimulator[toPrint]){
      //cout << "***CHECKKKK****";
      cout << st->leftSignFromSimulator[toPrint]->getValue();
    }
  }
  m.unlock();
  return 5;
}


PrintCommand::~PrintCommand(){}
