//
// Created by yuvalshechter
//

#include "Div.h"
/*
 * The function divided between two expressions.
 */

double Div::calculate() {

    if (this->getLeft() == 0) {
        return 0;
    }
    if (this->getRight() == 0) {
        throw ("can't divide at 0");
    } else {
        return (this->getLeft()->calculate() / this->getRight()->calculate());
    }

}