//
// Created by yuvalshechter on 24/12/2019.
//
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include "ConnectCommand.h"
#include <thread>
using namespace std;
int cs;
ConnectCommand::ConnectCommand(symbolTables *sT){
    st = sT;
}

void ConnectCommand:: sendSet(string msg, int socket) {
    int is_sent = send(socket , (char*)msg.c_str() , strlen((char*)msg.c_str()) , 0);
    if (is_sent == -1) {
        std::cout<<"Error sending message"<<std::endl;
    } else {
        //std::cout<< msg << " message sent to server"<<std::endl;
    }
}


//thread
void ConnectCommand::clientThread(int client_socket) {
    //if here we made a connection
    while(flag) {
        /*int is_sent = send(socket , (char*)msg.c_str() , strlen((char*)msg.c_str()) , 0);
        if (is_sent == -1) {
            std::cout<<"Error sending message"<<std::endl;
        } else {
            std::cout<< msg << " message sent to server"<<std::endl;
        }*/
    }
    close(client_socket);
}

//socket
int ConnectCommand ::execute(int i) {

    //create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    cs = client_socket;
    if (client_socket == -1) {
        //error
        std::cerr << "Could not create a socket"<<std::endl;
        return -1;
    }

    //We need to create a sockaddr obj to hold address of server
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;//IP4
    address.sin_addr.s_addr = inet_addr("127.0.0.1");  //the localhost address
    address.sin_port = htons(stoi(vec[i+3]));
    //we need to convert our number (both port & localhost)
    // to a number that the network understands.

    // Requesting a connection with the server on local host with port 8081
    int is_connect = connect(client_socket, (struct sockaddr *)&address, sizeof(address));
    if (is_connect == -1) {
        std::cerr << "Could not connect to host server"<<std::endl;
        return -2;
    } else {
        std::cout<<"Client is now connected to server" <<std::endl;
    }

    this_thread::sleep_for(chrono::seconds(10));
    thread threadCC([=]{ clientThread(client_socket);});
    threadCC.detach();
    return 6;
}

ConnectCommand::~ConnectCommand(){}