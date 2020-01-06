
//
// Created by yuvalshechter on 21/12/2019.
//

#ifndef FLIGHTPROJECT_LEXER_H
#define FLIGHTPROJECT_LEXER_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#define SPACE " "
using namespace std;

class lexer {
    vector<string> v;
    void lex_func(string &inp_str);

public:
    lexer(){}
    vector<string> open_file_for_lex(string fileName);
    ~lexer(){}
};


#endif //EX3_LEXER_H
