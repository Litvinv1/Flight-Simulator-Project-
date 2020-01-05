//
// Created by yuvalshechter
//

#include "UPlus.h"
using namespace std;
/*
 * This function get operator plus and number and return the positive number.
 */
double UPlus::calculate() {
    return (this->getExpression()-> calculate());
}