//
// Created by yuvalshechter on 04/01/2020.
//

#include <mutex>
#include "LoopCommand.h"

LoopCommand:: LoopCommand(symbolTables* sT){
    st = sT;
}

int LoopCommand::execute(int i) {
    mutex m;
    bool lock = m.try_lock();
    if (!lock) {
        cout << "unable to lock mutex in LoopCommand" <<endl;
    }
    varName = vec[i+1];
    op = vec[i+2];
    val = stof(vec[i+3]);
    int endScope = setCommandsScope(i);
    //int k = i;
    while (isSatisfied()) {
        int n = i+6;
        for (unsigned int j=0;j<commands.size();j++) {
            //Command* cScope = cmdMap[scopeVec[j]];
            n = n + commands[j]->execute(n);
        }
    }
    m.unlock();
    return endScope;
}

int LoopCommand::setCommandsScope(int index) {
    //find end of scope
    commands.clear();
    int j = index;
    int scopeSize = 0;
    while (vec[j] != "}") {
        string word = vec[j];
        if(word[0]=='\t'){
            //erasing tab
            word.erase(0,1);
            if (!cmdMap[word] && vec[j+1] == "=") {
                commands.push_back(cmdMap[vec[j+1]]);
            } else if (cmdMap[word]) {
                commands.push_back(cmdMap[word]);
            }
        }
        j++;
        scopeSize++;
    }
    return scopeSize+2;
}