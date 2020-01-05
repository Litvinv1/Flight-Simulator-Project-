//
// Created by adam on 02/01/2020.
//

#include <mutex>
#include "AssignCommand.h"
#include "ConnectCommand.h"
//extern int cs;

AssignCommand::AssignCommand(symbolTables *sT) {
  st = sT;
};

int AssignCommand::execute(int index){
  mutex m;
  bool lock = m.try_lock();
  if (!lock) {
    cout << "unable to lock mutex in AssignCommand" <<endl;
  }
  //if the index in the vector is variable in the rightSignToSimulator map and there is equal sign after it
  if((st->rightSignToSimulator[vec[index]]) && (vec[index+1] == "=")){
    //update the value of this variable
    st->rightSignToSimulator[vec[index]]->setValue(stof(vec[index+2]));
    //the message we want to send tot eh simulator
    string setMsg = "set " + st->rightSignToSimulator[vec[index]]->getSim() + " " +
                    to_string(st->rightSignToSimulator[vec[index]]->getValue()) + "\r\n";
    ConnectCommand* c = new ConnectCommand(st);
    c->sendSet(setMsg, cs);
    //check to see if the value is update
    cout<< st->rightSignToSimulator[vec[index]]->getSim() << " = " << st->rightSignToSimulator[vec[index]]->getValue()<< endl;
  }
  m.unlock();

  return 4;
}

/*int AssignCommand:: returnJumps(int j) {
    return 4;
}*/
AssignCommand::~AssignCommand(){};
