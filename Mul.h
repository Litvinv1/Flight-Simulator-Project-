//
// Created by yuvalshechter
//

#ifndef EX1_MUL_H
#define EX1_MUL_H
#include "BinaryOperator.h"
using namespace std;

class Mul : public BinaryOperator {
public:
    Mul(Expression* left1,Expression* right1) : BinaryOperator(left1, right1){};
    virtual double calculate ();
    virtual ~Mul(){};

};

#endif //EX1_MUL_H
