//
// Created by yuvalshechter
//

#include "ex1.h"


regex negNum("(\\-)(0|[1-9][0-9]*)(\\.[0-9]+)?");
regex equalOpr("=");
regex validNum("^(\\()(\\-|\\+)?(0|[1-9][0-9]*)(\\.[0-9]+)?(\\))");
regex colon(";");
regex newOpr("\\+|\\-|\\/|\\*|\\(|\\$|\\#|\\)");
regex varAndNum("[a-zA-Z][0-9]*");
regex numOrVar("^((0|[1-9][0-9]*)(\\.[0-9]+)?)|^[a-zA-Z][0-9]*");
regex oprNumVar ("(\\~|\\!|\\@|\\#|\\$|\\%|\\^|\\&|\\*|\\(|\\))|([0-9]+[a-zA-Z]+)");
regex validOpr("(\\+|\\-|\\/|\\*)+(\\+|\\-|\\/|\\*)+");
stack<string>oprStack;
queue<string>numQueue;
string temp;
string tempVars;
smatch ma;
bool ok;
Expression* r;
Expression* l;


Expression *Interpreter::interpret(string infix) {
    int counter = 0;
    if(regex_search(infix, match, validOpr)){
        throw (const char*)"illegal math expression";
    }
    for (int unsigned i= 0; i < infix.size(); i++) {
        if (infix[i] == '-' && infix[i + 1] == '(') {
            infix[i] = '$';
        }
        if (infix[i] == '+' && infix[i + 1] == '(') {
            infix[i] = '#';
        }
        if(infix[i] == '('){
            counter++;
        }
        if(infix[i] == ')'){
            counter--;
        }
    }
    if(counter != 0 ){
        throw (const char*)"illegal math expression";
    }
    while (!infix.empty()) {
        if (regex_search(infix, match, validNum)) {
            numQueue.push(match.str());
        } else {
            if (regex_search(infix, match, numOrVar)) {
                numQueue.push(match.str());
            } else {
                if (regex_search(infix, match, newOpr)) {
                    if (oprStack.empty() || match.str() == "(" || oprStack.top() == "(") {
                        oprStack.push(match.str());
                    } else {
                        if ((oprStack.top() == "+" || oprStack.top() == "-" || oprStack.top() == "$"||oprStack.top() == "#")&& match.str()!= ")") {
                            oprStack.push(match.str());
                        } else {
                            if(match.str() == ")"){
                                while (temp != "(" && !oprStack.empty()) {
                                    temp = oprStack.top();
                                    if (temp != "(") {
                                        oprStack.pop();
                                        numQueue.push(temp);
                                    } else {
                                        oprStack.pop();
                                    }
                                }
                            } else{
                                if (oprStack.top() == "*" || oprStack.top() == "/") {
                                    if (match.str() == "+" || match.str() == "-" || match.str() == "$" || oprStack.top() == "#") {
                                        temp = oprStack.top();
                                        oprStack.pop();
                                        oprStack.push(match.str());
                                        numQueue.push(temp);
                                    }
                                    if (match.str() == "*" || match.str() == "/") {
                                        temp = oprStack.top();
                                        oprStack.pop();
                                        oprStack.push(match.str());
                                        numQueue.push(temp);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        infix = match.suffix();
    }
    while (!oprStack.empty()) {
        temp = oprStack.top();
        oprStack.pop();
        if (temp != "(") {
            numQueue.push(temp);
        }
    }
    stack<Expression *> expStack;
    string qstr;
    while (!numQueue.empty()) {
        ok = false;
        qstr = numQueue.front();
        if (regex_search(qstr, match, numOrVar)) {
            if (regex_search(qstr, ma, varAndNum)) {
                int i = 0;
                while (ma.str() != variables.at(i)->getName()) {
                    i++;
                }
                expStack.push(variables.at(i));
            } else {
                expStack.push(new Value(stod(match.str())));
            }
            ok = true;
        }
        if (regex_search(qstr, match, validNum)) {
            string s = match.str();
            regex_search(s, ma, negNum);
            expStack.push(new Value(stod(ma.str())));
            ok = true;
        }
        if (regex_search(qstr, match, newOpr) && ok == false) {
            if (match.str() == "$" || match.str() == "#") {
                r = expStack.top();
                expStack.pop();
                if (match.str() == "$")
                    expStack.push(new UMinus(r));
                if (match.str() == "#"){
                    if(expStack.size()>1){
                        l=expStack.top();
                        expStack.pop();
                        expStack.push(new Value((new Plus(r, l))->calculate()));
                    }else{
                        expStack.push(new UPlus(r));
                    }
                }
            } else {
                r = expStack.top();
                expStack.pop();
                l = expStack.top();
                expStack.pop();
                if (match.str() == "*") {
                    expStack.push(new Value((new Mul(r, l))->calculate()));
                }
                if (match.str() == "+") {
                    expStack.push(new Value((new Plus(r, l))->calculate()));
                }
                if (match.str() == "/") {
                    expStack.push(new Value((new Div(l, r))->calculate()));
                }
                if (match.str() == "-") {
                    expStack.push(new Value((new Minus(r, l))->calculate()));
                }
            }
        }
        numQueue.pop();
    }
    if(expStack.size()>1){
        r=expStack.top();
        expStack.pop();
        l=expStack.top();
        expStack.pop();
        expStack.push(new Value((new Plus(r, l))->calculate()));
    }
    return expStack.top();
}

void Interpreter::setVariables(string variable) {
    //if the expression is not number or operator or variable throw exception.
    if(regex_search(variable,match,oprNumVar)){
        throw(const char*)"illegal variable assignment";
    }else {
        //variable is a string that we get.
        while(!variable.empty()){
            //This function take only the first expression each time until the ; such as x=4.
            if(regex_search(variable,match,colon)){
                //tempVars is a string the contain the expression until the ;.
                tempVars = match.prefix().str();
                //update string variable to be the suffix string that is after the ;.
                variable = match.suffix().str();
                //we separate the expression such as x=4 to string variable-var and double number-val
                regex_search(tempVars,ma,equalOpr);
                //if the size of the variables vector is 0
                if(variables.size()==0){
                    variables.push_back(new Variable(ma.prefix().str(),stod( ma.suffix())));
                } else {
                    ok= false;
                    for (int unsigned i = 0; i < variables.size(); i++) {
                        if (variables.at(i)->getName() == ma.prefix().str()) {
                            variables[i]->setValue(stod(ma.suffix()));
                            ok=true;
                        }
                    }
                    if(ok==false){
                        variables.push_back(new Variable(ma.prefix().str(), stod(ma.suffix())));
                    }
                    variable = match.suffix();
                }
            } else{
                regex_search(variable,match,equalOpr);
                if(variables.size()==0){
                    variables.push_back(new Variable(match.prefix().str(),stod( match.suffix())));
                } else{
                    ok= false;
                    for(int unsigned i=0 ;i<variables.size();i++){
                        if (variables.at(i)->getName() == match.prefix().str()) {
                            variables[i]->setValue(stod(match.suffix()));
                            ok=true;
                        }
                    }
                    if(ok==false){
                        variables.push_back(new Variable(match.prefix().str(),stod( match.suffix())));
                    }
                }
                variable.clear();
            }
        }
    }
}