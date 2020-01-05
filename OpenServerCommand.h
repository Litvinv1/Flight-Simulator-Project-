//
// Created by yuvalshechter on 22/12/2019.
//

#ifndef EX3_OPENSERVERCOMMAND_H
#define EX3_OPENSERVERCOMMAND_H
#include "Command.h"
#include "simulatorFlightObject.h"
#include "symbolTables.h"
#include <stdio.h>
#include <string.h>
#include <thread>
#include <unordered_map>
#include <vector>
using namespace std;

//unordered_map<int,string> matchMap;
extern vector<string>vec;
extern unordered_map<string, simulatorFlightObject*> rightSighToSimulator;
extern unordered_map<string, simulatorFlightObject*> leftSignFromSimulator;

/**
 * This class continue to read the args she need and call static function that opens data server according to the port number.
 * the server open in thread to continue reading while the server waiting for client.
 * This class is part of command pattern.
 **/
class OpenServerCommand : public Command {
private:
  unordered_map<int,string> matchMap;
  symbolTables *st;

public:
  OpenServerCommand(symbolTables *sT);
  virtual int execute(int);
  //void initMap();
  void updateLeftFromSim(string bufLine);
  void serverThread(int client_socket);
  virtual ~OpenServerCommand();

  //void updateLeftFromSim(string bufLine);
};


#endif //EX3_OPENSERVERCOMMAND_H
