//
// Created by yuvalshechter on 03/01/2020.
//

#include "SleepCommand.h"
#include <chrono>
#include <thread>

SleepCommand::SleepCommand(symbolTables* sT){
    st = sT;
}

int SleepCommand::execute(int index) {
    //sleepCmd is a string type that contain the value of the time that the simulator should wait
    string sleepCmd = vec[index+2];
    //convert string to int
    int timeToSleep = stoi(sleepCmd);
    //time for sleep
    this_thread::sleep_for(chrono::milliseconds(timeToSleep));
    return 5;
}



SleepCommand::~SleepCommand(){}