//
// Created by yuvalshechter
//

#include "Mul.h"
using namespace std;

/*
 * The function multiply between two expressions.
 * Return the expression after plus operator between them.
 */

double Mul::calculate() {
    return(this-> getLeft()-> calculate() * this-> getRight()-> calculate());

}