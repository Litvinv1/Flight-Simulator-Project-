//
// Created by yuvalshechter
//

#include "Value.h"
using namespace std;

/*
 * This function calculate the value and return it back.
 */

Value ::Value(double val1)  {
    this->val = val1;
}

double Value::calculate() {
    return this-> val;
}

