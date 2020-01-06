//
// Created by yuvalshechter on 03/01/2020.
//
#include <mutex>
#include "ConditionParser.h"
ConditionParser::ConditionParser(){}

ConditionParser::ConditionParser(symbolTables* sT){
    st = sT;
}

bool ConditionParser::isSatisfied() {
    mutex m;
    m.lock();
    bool b;
    if (op == "<") {
        b= st->leftSignFromSimulator[varName]->getValue() < val;
        m.unlock();
        return b;
    } else if (op == ">") {
        b= st->leftSignFromSimulator[varName]->getValue() < val;
        m.unlock();
        return b;
    } else if (op == "<=") {
        b= st->leftSignFromSimulator[varName]->getValue() < val;
        m.unlock();
        return b;
    } else if (op == ">=") {
        b= st->leftSignFromSimulator[varName]->getValue() < val;
        m.unlock();
        return b;
    } else if (op == "==") {
        b= st->leftSignFromSimulator[varName]->getValue() < val;
        m.unlock();
        return b;
    } else if (op == "!=") {
        b= st->leftSignFromSimulator[varName]->getValue() < val;
        m.unlock();
        return b;
    }
    return false;
}


int ConditionParser::execute(int i) {
    return i;
}

ConditionParser:: ~ConditionParser(){}