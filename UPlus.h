//
// Created by yuvalshechter
//

#ifndef EX1_UPLUS_H
#define EX1_UPLUS_H
#include "UnaryOperator.h"
using namespace std;

class UPlus :  public UnaryOperator {
    Expression* pos;

public:
    UPlus(Expression* pos1) : UnaryOperator(pos1){};
    virtual double calculate();
    virtual ~UPlus(){};

};

#endif //EX1_UPLUS_H
