//
// Created by yuvalshechter
//

#include "UnaryOperator.h"
/*
 * Constructor to the class UnaryOperator.
 */

UnaryOperator :: UnaryOperator(Expression* exp1) {
    this-> exp = exp1;
}

// This function return the expression.
Expression* UnaryOperator :: getExpression(){
    return (this-> exp);
}