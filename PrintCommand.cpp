//
// Created by yuvalshechter on 02/01/2020.
//

#include "PrintCommand.h"
#include "thread"
//
// Created by adam on 02/01/2020.
//

#include <iostream>
#include <mutex>

using namespace std;

PrintCommand::PrintCommand(symbolTables* sT){
    st = sT;
}

int PrintCommand::execute(int index) {

    mutex m;
    bool lock = m.try_lock();
    if (!lock) {
        cout << "unable to lock mutex in defineVarCommand" <<endl;
    }
    // toPrint is a print command that we should print
    string toPrint = vec[index+2];
    //if there is quotation marks we should print without it
    if(toPrint[0] == '"') {
        //cut the quotation marks
        toPrint = toPrint.substr(1, toPrint.length() - 2);
        if (toPrint == "done") {
            flag = false;
        }
        this_thread::sleep_for(chrono::seconds(1));
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
            cout << st->leftSignFromSimulator[toPrint]->getValue() << endl;
        }
        //cout << "check";
    }
    m.unlock();
    return 5;
}


PrintCommand::~PrintCommand(){}