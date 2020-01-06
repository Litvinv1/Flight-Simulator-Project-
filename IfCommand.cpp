//
// Created by yuvalshechter on 05/01/2020.
//

#include <mutex>
#include "IfCommand.h"
IfCommand::IfCommand(symbolTables *sT) {
    st = sT;
}

int IfCommand::execute(int i) {
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
    if (isSatisfied()) {
        unsigned int n = i+6;
        for (unsigned int j=0;j<commands.size();j++) {
            n = n + commands[j]->execute(n);
        }
    }
    m.unlock();
    return endScope;
}

int IfCommand::setCommandsScope(int index) {
    //find end of scope
    unsigned int j = index;
    int scopeSize = 0;
    while (vec[j] != "}") {
        string word = vec[j];
        if(word[0]=='\t'){
            //erasing tab
            word.erase(0,1);
            commands.push_back(cmdMap[word]);
        }
        j++;
        scopeSize++;
    }
    return scopeSize+2;
}