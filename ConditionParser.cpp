//
// Created by yuvalshechter on 03/01/2020.
//

#include "ConditionParser.h"
#include <mutex>

ConditionParser::ConditionParser(){}
ConditionParser::ConditionParser(symbolTables* sT){
  st = sT;
};

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
}

int ConditionParser::setCommandsScope(int index) {
  //find end of scope
  int j = index;
  int scopeSize = 0;
  while (vec[j] != "}") {
    string word = vec[j];
    if(word[0]=='\t'){
      //erasing tab
      word.erase(0,1);
      commands.push_back(cmdMap[word]);
    }
    j++;
    scopeSize++;
  }
  return scopeSize+2;
}

int ConditionParser::execute(int i) {
 return 0;
}
ConditionParser:: ~ConditionParser(){};
