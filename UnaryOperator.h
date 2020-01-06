//
// Created by yuvalshechter

#ifndef EX1_UNARYOPERATOR_H
#define EX1_UNARYOPERATOR_H
#include "Expression.h"
using namespace std;

class UnaryOperator : public Expression {
protected:
    Expression* exp;

public:
    UnaryOperator(Expression* exp);
    virtual Expression* getExpression();
    virtual double calculate()= 0;
    virtual ~UnaryOperator(){};
};

#endif //EX1_UNARYOPERATOR_H
