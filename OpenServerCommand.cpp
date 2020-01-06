//
// Created by yuvalshechter on 22/12/2019.
//

#include "OpenServerCommand.h"
#include "simulatorFlightObject.h"
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <unordered_map>
#include <stdio.h>
#include <string.h>
#include <mutex>
//#define  PORT 5400
using namespace std;



OpenServerCommand::OpenServerCommand(symbolTables* sT){
    st = sT;
}

void OpenServerCommand:: updateLeftFromSim(string bufLine) {
    unordered_map<int,string> matchMap ({
                                               {1, "/instrumentation/airspeed-indicator/indicated-speed-kt"},
                                               {2, "/sim/time/warp"},
                                               {3, "/controls/switches/magnetos"},
                                               {4, "/instrumentation/heading-indicator/offset-deg"},
                                               {5, "/instrumentation/altimeter/indicated-altitude-ft"},
                                               {6, "/instrumentation/altimeter/pressure-alt-ft"},
                                               {7, "/instrumentation/attitude-indicator/indicated-pitch-deg"},
                                               {8, "/instrumentation/attitude-indicator/indicated-roll-deg"},
                                               {9, "/instrumentation/attitude-indicator/internal-pitch-deg"},
                                               {10, "/instrumentation/attitude-indicator/internal-roll-deg"},
                                               {11, "/instrumentation/encoder/indicated-altitude-ft"},
                                               {12, "/instrumentation/encoder/pressure-alt-ft"},
                                               {13, "/instrumentation/gps/indicated-altitude-ft"},
                                               {14, "/instrumentation/gps/indicated-ground-speed-kt"},
                                               {15, "/instrumentation/gps/indicated-vertical-speed"},
                                               {16, "/instrumentation/heading-indicator/indicated-heading-deg"},
                                               {17, "/instrumentation/magnetic-compass/indicated-heading-deg"},
                                               {18, "/instrumentation/slip-skid-ball/indicated-slip-skid"},
                                               {19, "/instrumentation/turn-indicator/indicated-turn-rate"},
                                               {20, "/instrumentation/vertical-speed-indicator/indicated-speed-fpm"},
                                               {21, "/controls/flight/aileron"},
                                               {22, "/controls/flight/elevator"},
                                               {23, "/controls/flight/rudder"},
                                               {24, "/controls/flight/flaps"},
                                               {25, "/controls/engines/engine/throttle"},
                                               {26, "/controls/engines/current-engine/throttle"},
                                               {27, "/controls/switches/master-avionics"},
                                               {28, "/controls/switches/starter"},
                                               {29, "/engines/active-engine/auto-start"},
                                               {30, "/controls/flight/speedbrake"},
                                               {31, "/sim/model/c172p/brake-parking"},
                                               {32, "/controls/engines/engine/primer"},
                                               {33, "/controls/engines/current-engine/mixture"},
                                               {34, "/controls/switches/master-bat"},
                                               {35, "/controls/switches/master-alt"},
                                               {36, "/engines/engine/rpm"}
                                       });
    //mutex m;
    //bool lock = m.try_lock();
    //if (!lock) {
    //    cout << "unable to lock mutex in openServerCommand" <<endl;
    //}
    string delimiter(",");
    int pos = bufLine.find(delimiter);
    string val;
    int i=1;
    string simToUpdate;
    //fixing problem of updating the rpm last var
    while ((pos!= -1) || (i == 36)) {
        //lets get the sim to update from our matchMap
        simToUpdate = matchMap[i];
        //thats the value we need to use
        if (i==36) {
            val = bufLine.substr(0, bufLine.length());
        } else {
            val = bufLine.substr(0, pos);
        }
        //now we search in the leftMap the object
        //if (!st->leftSignFromSimulator.empty()) {
            for (auto &it: st->leftSignFromSimulator) {

                if (it.second->getSim() == simToUpdate) {
                    it.second->setValue(stof(val));
                }
            }
        //}
        //std::cout << val << endl;
        bufLine.erase(0, pos + delimiter.length());
        pos = bufLine.find(delimiter);
        i++;
    }
    //m.unlock();
    //last val is in bufLIne, the val for rpm!

    /*val = bufLine.substr(0, bufLine.length());
    if (bufLine.length() > 0 && leftSignFromSimulator["rpm"]) {
    leftSignFromSimulator["rpm"]->setValue(stof(val));
    }*/
}

//thread
void OpenServerCommand:: serverThread(int client_socket){
    string bufLine;
    string bufRemainLine;
    //reading from the client
    //the thread will running as long we have connection
    while(flag) {
        char buffer[1024] = {0};
        int valread = read(client_socket, buffer, 1024);
        for(unsigned int i=0; i< sizeof(buffer); i++) {
            if (buffer[i] && buffer[i] != '\n') {
                bufLine += buffer[i];

            } else if (buffer[i] == '\n') {
                bufLine.insert(0, bufRemainLine);
                bufRemainLine.erase();
                updateLeftFromSim(bufLine);
                bufLine.erase();
            }
        }
        bufRemainLine = bufLine;
        bufLine.erase();
        if (valread == -1){
            throw "error reading from the socket";
        }
    }
    close(client_socket);
}


//socket
//open data server for connect and call a thread to run
int OpenServerCommand :: execute (int i) {
    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket"<<std::endl;
        return -1;
    }
    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine

    address.sin_port = htons(stoi(vec[i+2]));
    //we need to convert our number
    // to a number that the network understands.
    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr<<"Could not bind the socket to an IP"<<std::endl;
        return -2;
    }
    //making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr<<"Error during listening command"<<std::endl;
        return -3;
    } else{
        std::cout<<"Server is now listening ..."<<std::endl;
    }
    // accepting a client
    int client_socket = accept(socketfd, (struct sockaddr *)&address,
                               (socklen_t*)&address);
    if (client_socket == -1) {
        std::cerr<<"Error accepting client"<<std::endl;
        return -4;
    }

    close(socketfd); //closing the listening socket

    //celling to thread
    this_thread::sleep_for(chrono::seconds(10));
    //thread threadOSC([=]{serverThread(client_socket);});
    thread threadOSC([=]{serverThread(client_socket);});
    //threadOSC.join();
    //this_thread::sleep_for(chrono::seconds(200000));
    threadOSC.detach();

    //Jump 5 cells on the vector to get to the next command. 1:( 2:int port 3:) 4:enter(new line) 5:next command
    return 5;
}


OpenServerCommand:: ~OpenServerCommand(){}

