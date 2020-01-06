//
// Created by yuvalshechter
//

#ifndef EX1_VARIABLE_H
#define EX1_VARIABLE_H
#include <string>
#include "Expression.h"
using namespace std;

class Variable: public Expression{
private:
    Variable();

    string name;
    double value;

public:
    Variable(string name1, double value);
    Variable& operator+=(double num);
    Variable& operator-=(double num);
    Variable& operator++();
    Variable& operator--();
    Variable& operator++(int);
    Variable& operator--(int);
    string getName();
    void setValue(double v);
    double calculate();
    virtual ~Variable(){};
};


#endif //EX1_VARIABLE_H
