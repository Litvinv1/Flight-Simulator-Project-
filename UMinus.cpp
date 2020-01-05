//
// Created by yuvalshechter
//

#include "UMinus.h"
using namespace std;

/*
 * This function get a number and negative operator and return the negative number.
 */

double UMinus::calculate() {
    return (this-> getExpression()-> calculate()) * (-1);

}