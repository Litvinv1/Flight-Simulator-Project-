//
// Created by yuvalshechter on 26/12/2019.
//

#include "simulatorFlightObject.h"

simulatorFlightObject::simulatorFlightObject(float val, string sim){
  value = val;
  simPath = sim;
}

void simulatorFlightObject::setValue(float val) {
  value = val;
}

float simulatorFlightObject::getValue() {
  return value;
}


string simulatorFlightObject::getSim() {
  return simPath;
}

void simulatorFlightObject :: setSim(string sim) {
  simPath = sim;
}

simulatorFlightObject:: ~simulatorFlightObject(){};
