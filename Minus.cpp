//
// Created by yuvalshechter
//

#include "Minus.h"
using namespace std;

/*
 * The function minus between two expressions.
 * Return the expression after minus operator between the left expression to the right expression..
 */

double Minus::calculate() {
    return (this->getLeft()->calculate() - this->getRight()->calculate());

}