//
// Created by yuvalshechter on 26/12/2019.
//

#ifndef EX3_SIMULATORFLIGHTOBJECT_H
#define EX3_SIMULATORFLIGHTOBJECT_H

#include<string>
#include <iostream>

using namespace std;

/*
 * class holds the details about variables in the simulator
 */

class simulatorFlightObject {
private:
    float value;
    string simPath;

public:
    //Constructor
    simulatorFlightObject(float val, string sim);
    //Destructor
    ~simulatorFlightObject();
    float getValue();
    void setValue(float);
    void setSim(string sim);
    string getSim();
};


#endif //EX3_SIMULATORFLIGHTOBJECT_H
