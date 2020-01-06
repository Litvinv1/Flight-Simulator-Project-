//
// Created by yuvalshechter on 22/12/2019.
//

#ifndef EX3_OPENSERVERCOMMAND_H
#define EX3_OPENSERVERCOMMAND_H
#include "Command.h"
#include "simulatorFlightObject.h"
#include "symbolTables.h"
#include <thread>
#include <vector>
#include <unordered_map>
#include <stdio.h>
#include <string.h>
using namespace std;

extern vector<string>vec;
extern bool flag;

/**
 * This class continue to read the args she need and call static function that opens data server according to the port number.
 * the server open in thread to continue reading while the server waiting for client.
 * This class is part of command pattern.
 **/
class OpenServerCommand : public Command {
private:
    symbolTables* st;

public:
    OpenServerCommand(symbolTables* sT);
    virtual int execute(int);
    virtual ~OpenServerCommand();
    void updateLeftFromSim(string bufLine);
    void serverThread(int client_socket);
};


#endif //EX3_OPENSERVERCOMMAND_H