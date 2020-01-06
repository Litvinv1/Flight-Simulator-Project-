//
// Created by yuvalshechter
//

#ifndef EX1_BINARYOPERATOR_H
#define EX1_BINARYOPERATOR_H
#include "Expression.h"
using namespace std;

class BinaryOperator : public Expression {
protected:
    Expression *left;
    Expression *right;

public:
    BinaryOperator(Expression* left, Expression* right);
    virtual Expression* getLeft();
    virtual Expression* getRight();
    virtual double calculate()= 0;
    virtual ~BinaryOperator(){};

};


#endif //EX1_BINARYOPERATOR_H
