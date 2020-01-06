//
// Created by yuvalshechter
//

#include "BinaryOperator.h"
using namespace std;

/*
 * Constructor to the class BinaryOperator.
 */

BinaryOperator::BinaryOperator(Expression *left1, Expression *right1){
    this->left = left1;
    this->right = right1;
}

// This function return the left expression.
Expression* BinaryOperator::getLeft() {
    return (this-> left);
}

// This function return the right expression.
Expression* BinaryOperator::getRight()  {
    return (this-> right);
}