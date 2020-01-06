//
// Created by yuvalshechter
//

#include "Plus.h"
using namespace std;

/*
 * The function plus between two expressions.
 * Return the expression after plus operator between them.
 */
double Plus::calculate() {
    return(this-> getLeft()-> calculate() + this-> getRight()-> calculate());
}
