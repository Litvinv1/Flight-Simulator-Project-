//
// Created by yuvalshechter on 24/12/2019.
//

#ifndef EX3_CONNECTCOMMAND_H
#define EX3_CONNECTCOMMAND_H

#include "Command.h"
#include "symbolTables.h"

using namespace std;
extern bool flag;
extern vector<string>vec;
/**
 * This class is connecting the to simulator flight and send him values.
 * This class is part of command pattern.
 **/
class ConnectCommand : public Command {
private:
    symbolTables *st;

public:
    ConnectCommand(symbolTables* sT);
    ~ConnectCommand();
    virtual int execute(int i);
    void sendSet(string msg, int socket);

    void clientThread(int client_socket);
};




#endif //EX3_CONNECTCOMMAND_H
