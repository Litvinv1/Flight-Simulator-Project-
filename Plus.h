//
// Created by yuvalshechter
//

#ifndef EX1_PLUS_H
#define EX1_PLUS_H
#include "BinaryOperator.h"
using namespace std;

class Plus : public BinaryOperator {

public:
    Plus(Expression* left1, Expression* right1): BinaryOperator (left1, right1){};
    virtual double calculate ();
    virtual ~Plus(){};
};



#endif //EX1_PLUS_H
