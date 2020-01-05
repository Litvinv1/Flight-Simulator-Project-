//
// Created by yuvalshechter
//

#ifndef EX1_UMINUS_H
#define EX1_UMINUS_H
#include "UnaryOperator.h"
using namespace std;


class UMinus : public UnaryOperator{
    Expression* neg;

public:
    UMinus(Expression* neg1) : UnaryOperator(neg1){};
    virtual double calculate();
    virtual ~UMinus(){};


};


#endif //EX1_UMINUS_H
