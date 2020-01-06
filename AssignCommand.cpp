#include <mutex>
#include "AssignCommand.h"
#include "ConnectCommand.h"
#include "ex1.h"


AssignCommand::AssignCommand(symbolTables* sT) {
    st = sT;
}

bool AssignCommand:: is_number(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && ((isdigit(*it) || *it == '.'))) {
        ++it;
    }
    return !s.empty() && it == s.end();
}

int AssignCommand::execute(int index){
    mutex m;
    bool lock = m.try_lock();
    if (!lock) {
        cout << "unable to lock mutex in AssignCommand" <<endl;
    }
    //if the index in the vector is variable in the to sim map and there is equal sign after it
    string var = vec[index];
    if((st->rightSignToSimulator[vec[index]]) && (vec[index+1] == "=")){
        vector<string> exVec;
        string infExp = "";
        unsigned int j = index + 2;
        //create new parital vec
        while (vec[j] != "\n") {
            exVec.push_back(vec[j]);
            j++;
        }
        //change the variable names to teh actual value
        j = 0;
        while (j < exVec.size()) {
            //check if its a variable name
            if (isalpha(exVec[j][0])) {
                //check if its in one of the maps, and update
                if (st->leftSignFromSimulator[exVec[j]]) {
                    exVec[j] = st->leftSignFromSimulator[exVec[j]]->getValue();
                } else if (st->rightSignToSimulator[exVec[j]]) {
                    exVec[j] = to_string(st->rightSignToSimulator[exVec[j]]->getValue());
                } else {
                    cout << "No such variable name: " << var << endl;
                }
            }
            j++;
        }
        j = 0;
        //add parenthesis to make it easier for the interpreter
        while (j < exVec.size()) {
            if (MATH_OPERATORS.count(exVec[j]) != 0) {
                if (!is_number(exVec[j-1]) || j == 0) {
                    exVec[j] = "(" + exVec[j] + ")";
                }
            }
            j++;
        }
        j = 0;
        //create the full string
        while (j < exVec.size()) {
            infExp.append(exVec[j]);
            j++;
        }
        Interpreter i;
        //update the value of this variable
        st->rightSignToSimulator[var]->setValue(float(i.interpret(infExp)->calculate()));
        //the message we want to send to the simulator
        string setMsg = "set " + st->rightSignToSimulator[var]->getSim() + " " +
                to_string(st->rightSignToSimulator[var]->getValue()) + "\r\n";
        ConnectCommand* c = new ConnectCommand(st);
        c->sendSet(setMsg, cs);
    }
    m.unlock();
    //check how many jumps you need to get to next line
    int counter = 0;
    while (vec[index] != "\n") {
        index++;
        counter++;
    }
    return counter+1;
}


AssignCommand::~AssignCommand(){}
