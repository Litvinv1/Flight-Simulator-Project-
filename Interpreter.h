//
// Created by yuvalshechter
//

#define EX1_INTERPRETER_H
#define EX1_INTERPRETER_H

using namespace std;
#include <string>
#include <regex>
#include <stack>
#include <queue>
#include "ex1.h"

class Variable;

class Interpreter {
private:
smatch match;
vector<Variable*>variables;
public:
    Expression *interpret (string infix);
    void setVariables (string variable);
    Interpreter(){}
    ~Interpreter() = default;
};


