#include "lexer.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "Command.h"
#include "AssignCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "simulatorFlightObject.h"
#include "LoopCommand.h"
#include "symbolTables.h"
#include "IfCommand.h"
#include <iostream>
#include <thread>
#include <vector>
#include <unordered_map>
#include <unistd.h>
#include <netinet/in.h>
using namespace std;
bool flag;

vector<string>vec;
symbolTables st;
unordered_map<string,Command*> cmdMap({
                                          {"openDataServer", new OpenServerCommand(&st)},
                                          {"connectControlClient",new ConnectCommand(&st)},
                                          {"=", new AssignCommand(&st)},
                                          {"var", new DefineVarCommand(&st)},
                                          {"Print", new PrintCommand(&st)},
                                          {"Sleep", new SleepCommand(&st)},
                                          {"if", new IfCommand(&st)},
                                          {"while", new LoopCommand(&st)}
                                      });

/**
 * This class is the main class of the simulator flight
 */
int main(int argc, char const *argv[]) {
  lexer l;
  vec = l.open_file_for_lex("flytest.txt");
  for (int i = 0; i < vec.size(); i++) {
    cout << vec.at(i) << "||";
    // i += vec.at(i).execute();
  }


  /*//checking for OpenDataServerCommand class
  int i = 0;
  Command *c = new OpenServerCommand();
  c->execute(i);
  this_thread::sleep_for(chrono::seconds(11111));*/



  /*//checking for DefineVarCommand class and AssignCommand class
  int i=0;
  while (i < vec.size()-1) {
    if (vec[i] == "var") {
      Command *c = cmdMap[vec[i]];
      c->execute(i);
    } else {
      // c->print();
      // cout<< vec.size();
      AssignCommand *c1 = new AssignCommand();
      c1->execute(i);
    }
  }*/


  /*//checking for ConnectCommand class
  int i=0;
  Command *c1 = new ConnectCommand();
  c1->execute(i + 5);
  this_thread::sleep_for(chrono::seconds(11111));*/



  //checking for DefineVarCommand class
  int i = 0;
  //int num = 0;
  while (i < vec.size() - 1) {
    if (cmdMap[vec[i]]) {
      Command *c = cmdMap[vec[i]];
      i += c->execute(i);
      //delete c;
      //Assign
    } else if (vec[i+1] == "=") {
      Command *c = cmdMap[vec[i+1]];
      i += c->execute(i);
      //delete c;
    }
    //cout << "command num: " << num;
    //num++;
    //Condition

    if (vec[i] == "Print") {
        if (st.leftSignFromSimulator[vec[i+2]]) {
            cout <<st.leftSignFromSimulator[vec[i+2]]->getValue()<< "CHECK "  << endl;
        }
    }
    //c->print();
  }



  /*while (true) {
      cout << "leftSignFromSimulator: ****" << leftSignFromSimulator["rpm"]->getValue()<< endl;
      if (leftSignFromSimulator.size() > 0) {
          for (auto local_it = leftSignFromSimulator.begin(); local_it != leftSignFromSimulator.end(); ++local_it) {
              std::cout << "var name: " << local_it->first << " value: " << local_it->second->getValue() <<
                        " simPath: " << local_it->second->getSim();
              std::cout << std::endl;
          }
      } else {
          cout << "the map has no pairs";
      }
      cout << endl;

      /*cout << "rightSignToSimulator: " << endl;
      if (rightSignToSimulator.size() > 0) {
          for (auto local_it = rightSignToSimulator.begin(); local_it != rightSignToSimulator.end(); ++local_it) {
              std::cout << "var name: " << local_it->first << " value: " << local_it->second->getValue() <<
                        " simPath: " << local_it->second->getSim();
              std::cout << std::endl;
          }
      } else {
          cout << "the map has no pairs";
      }
      cout << endl;
  }*/
  //this_thread::sleep_for(chrono::seconds(100000));





//check the DefineVarCommand class and printCommand class AssignCommand class
  /* int i = 0;
   while (i < vec.size() - 1) {
       if (vec[i] == "var") {
           DefineVarCommand *c = new DefineVarCommand();
           i += c->execute(i);
       }
       if (vec[i] == "Print") {
           Command *cp = cmdMap[vec[i]];
           i += cp->execute(i);
       } else {
           AssignCommand *c1 = new AssignCommand();
           i += c1->execute(i);
       }
   }*/



  /*delete c;
  delete c1;
  delete cp;*/



  return 0;
}
