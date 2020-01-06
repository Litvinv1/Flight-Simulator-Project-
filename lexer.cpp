//
// Created by yuvalshechter on 22/12/2019.
//

#include "lexer.h"
#include <vector>
#include <string>
#include <fstream>
#include "list"
#include <algorithm>
#include <iostream>


using namespace std;

void lexer::lex_func(string &inp_str){
    //first were putting spaces everywhere we need to
    //string inp_str = input_str;
    string l;
    string cur_char, next_char;
    string temp;
    string operators[14] = {"!","(", "-", "+", "*", "/", ">",
                            "<", ")",",", "="};
    string next_operators[3] = {"-", ">", "="};
    string space_str = "~";
    bool is_string = false;
    for (unsigned int i = 0; i < inp_str.length(); i++) {
        cur_char = inp_str[i];
        next_char = inp_str[i+1];
        //cout << cur_char + " " + next_char << endl;
        if ((find(begin(operators), end(operators), cur_char) != end(operators)) &&
            (find(begin(next_operators), end(next_operators), next_char) != end(next_operators))){
            cur_char.append(next_char);
            i++;
            next_char = inp_str[i] + inp_str[i + 1];
        } else {
            cur_char = inp_str[i];
        }
        if (cur_char == "\"") {
            is_string = !is_string;
            //cout << "its a string" << is_string << endl;
            temp.append(cur_char);
            continue;
        }
        if ((!is_string && (find(begin(operators), end(operators), cur_char) != end(operators)))
            || (!is_string && cur_char==" ")){
            /*(find(begin(operators), end(operators), next_char) != end(operators)))*/

            string to_replace = "~" + cur_char + "~";
            temp.append(to_replace);

            //else its string that should stick together
        } else {
            temp.append(cur_char);
        }
    }
    inp_str = temp;

    while(!inp_str.empty()) {
        l = inp_str.substr(0, inp_str.find(space_str));

        if(l.empty() == 1) {
            inp_str.erase(0, inp_str.find(space_str) + 1);
            continue;
        }
        if (l != " "&& l!=",") {
            v.push_back(l);
        }
        if(inp_str.find(space_str)==string::npos){
            inp_str ="";
        } else {
            inp_str.erase(0, inp_str.find(space_str) + space_str.length());
        }
    }
}


vector<string> lexer:: open_file_for_lex(string fileName) {
    if (fileName.find("txt") != string::npos) {
        ifstream readFile(fileName);
        string line;
        if (!readFile.is_open()) {
            cout << "error opening the file\n";
            exit(1);
        }
        while (!readFile.eof()) {
            getline(readFile, line);
            lex_func(line);
            v.push_back("\n");
        }
        readFile.close();
        return v;
    } else {
        //its a string
        lex_func(fileName);
        v.push_back("\n");
    }
    return v;
}