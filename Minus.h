//
// Created by yuvalshechter
//

#ifndef EX1_MINUS_H
#define EX1_MINUS_H
#include "BinaryOperator.h"
using namespace std;

class Minus : public BinaryOperator {
public:
    Minus(Expression* left1,Expression* right1) : BinaryOperator(left1, right1){};

    virtual double calculate ();
    virtual ~Minus(){};

};

#endif //EX1_MINUS_H
