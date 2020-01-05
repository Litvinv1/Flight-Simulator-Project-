//
// Created by yuvalshechter
//

#ifndef EX1_VALUE_H
#define EX1_VALUE_H
#include "Expression.h"
using namespace std;

class Value : public Expression {
private:
    double val;

public:
    Value(double val);
    virtual double calculate();
    virtual ~Value(){};
};


#endif //EX1_VALUE_H
