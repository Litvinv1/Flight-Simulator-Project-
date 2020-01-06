//
// Created by yuvalshechter on 25/12/2019.
//

#include <iomanip>
#include <mutex>
#include "DefineVarCommand.h"


DefineVarCommand::DefineVarCommand(symbolTables* sT){
    st = sT;
}

//vec is the vector of strings that we get from the lexer.
int DefineVarCommand::execute(int index) {
    //mutex m;
    //bool lock = m.try_lock();
    //if (!lock) {
    //    cout << "unable to lock mutex in defineVarCommand" <<endl;
    //}
    if (vec[index + 2] == "->") {
        //if the variable is already exist update the sim path for this variable
        if (st->rightSignToSimulator[vec[index + 1]]) {
            st->rightSignToSimulator[vec[index + 1]]->setSim(vec[index + 5]);
        } else {
            //the variable is not exist, creat new object for this variable that include the name of the var, sim path and value equal 0
            string variable = vec[index + 1];
            string simPath = vec[index + 5];
            //cutting the sim path to be without the quotation marks
            simPath = simPath.substr(1, simPath.length()-2);
            st->rightSignToSimulator[variable] = new simulatorFlightObject(0,simPath);
        }
    } else if (vec[index + 2] == "<-") {
        //if the variable is already exist update the sim path for this variable
        if (st->leftSignFromSimulator[vec[index + 1]]) {
            st->leftSignFromSimulator[vec[index + 1]]->setSim(vec[index + 5]);
        } else {
            //the variable is not exist, creat new object for this variable that include the name of the var, sim path and value equal 0
            string variable = vec[index + 1];
            string simPath = vec[index + 5];
            //cutting the sim path to be without the quotation marks
            simPath = simPath.substr(1, simPath.length()-2);
            st->leftSignFromSimulator[variable] = new simulatorFlightObject(0,simPath);
        }
    } else if(vec[index+2] == "="){
        //if there is equal sign after the name of the variable like: "var h0 = heading"
        string var = vec[index+1]; // var is the name of the variable such as h0
        //float val;
        vector<string> exVec;
        string infExp = "";
        unsigned int j = index + 3;
        //create new parital vec
        while (vec[j] != "\n") {
            exVec.push_back(vec[j]);
            j++;
        }
        //change var names with float values
        j = 0;
        while (j < exVec.size()) {
            //check if its a variable name
            if (isalpha(exVec[j][0])) {
                //check if its in one of the maps
                if (st->rightSignToSimulator[exVec[j]]) {
                    exVec[j] = st->rightSignToSimulator[exVec[j]]->getValue();
                } else if (st->leftSignFromSimulator[exVec[j]]) {
                    exVec[j] = to_string(st->leftSignFromSimulator[exVec[j]]->getValue());
                }
            }
            j++;
        }

        //and then we append all the expression together
        j = 0;
        while (j < exVec.size()) {
            infExp.append(exVec[j]);
            j++;
        }
        Interpreter i;

        //if the variable is exist in the rightSignToSimulator map
        if(st->rightSignToSimulator[var]){
            //lets update the value in the variable
            st->rightSignToSimulator[var]->setValue(float(i.interpret(infExp)->calculate()));
            //if the variable is exist in the leftSignFromSimulator map
        } else if(st->leftSignFromSimulator[var]) {
            //var is contain the value of the variable that was equal to him (the value of heading)
            st->leftSignFromSimulator[var]->setValue(float(i.interpret(infExp)->calculate()));
        } else {
            st->leftSignFromSimulator[var] = new simulatorFlightObject(float(i.interpret(infExp)->calculate()),var);
            //st->leftSignFromSimulator[var]->setValue(float(i.interpret(infExp)->calculate()));
            //cout << st->leftSignFromSimulator[var]->getValue()<<endl;

        }
        //m.unlock();
        return 6-1;
    }
    //m.unlock();
    return 8;
}


//just for us to check
/*void DefineVarCommand::print(){
       for(auto iter= rightSignToSimulator.begin(); iter!= rightSignToSimulator.end(); iter++){
           cout << iter->first <<'\t' << iter->second->getValue() << '\t'<< iter->second->getSim() << "\n";
       }
        cout<< endl;

    for(auto iter= leftSignFromSimulator.begin(); iter!= leftSignFromSimulator.end(); iter++){
        cout << iter->first <<'\t' << iter->second->getValue() <<'\t' << iter->second->getSim() << "\n";
    }
    cout<< endl;
}*/


DefineVarCommand :: ~DefineVarCommand(){}