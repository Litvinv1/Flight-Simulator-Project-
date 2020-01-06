//
// Created by yuvalshechter
//

#include "Variable.h"
using namespace std;

/*
 * This function calculate the value variable.
 */

Variable::Variable(string names, double valuess) {
    this -> name = names;
    this -> value = valuess;
}
Variable& Variable :: operator++(){
    ++value;
    return *this;
}
Variable& Variable :: operator--(){
    --value;
    return *this;
}
Variable& Variable :: operator++(int){
    value++;
    return *this;
}
Variable& Variable :: operator--(int){
    value--;
    return *this;
}
Variable& Variable :: operator+=(double num1){
    value += num1;
    return *this;
}
Variable& Variable :: operator-=(double num2){
    value -= num2;
    return *this;
}
double Variable ::calculate() {
    return this->value;
}

string Variable::getName() {
    return this->name;
}
void Variable::setValue(double v)  {
    this->value = v;
}
