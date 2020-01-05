//
// Created by yuvalshechter
//

#ifndef EX1_DIV_H
#define EX1_DIV_H
#include "BinaryOperator.h"
using namespace std;

class Div : public BinaryOperator {
public:
    Div(Expression* left1,Expression* right1) : BinaryOperator(left1, right1){};

    virtual  double calculate ();

};



#endif //EX1_DIV_H
