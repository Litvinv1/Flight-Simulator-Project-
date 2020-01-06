# Flight Simulator
by Vadim Litvinov & Yuval Shechter

## Description
This project is Interpreter for a FlightGear flight simulator. The program connects to the simulator and flys the aircraft based on the user's command that provide from the "fly.txt".

## Prerequisites
Linux environment to run the code.
clion program for the code in c++.

## Installing Instructions
1. Download and install the simulator to your computer - https://www.flightgear.org/download/
2. Add the generic_small.xml to the file /data/Protocol directory where you installed the simulator
3. Reat down the following settings in the 'Settings' tab in the simulator:
--telnet=socket,in,10,127.0.0.1,5402,tcp
--generic=socket,out,10,127.0.0.1,5400,tcp,generic_small
This commands will open two communication sockets - 'in' where you send commands to the simulator, and 'out' where you receive data from it.

## Running
1. Exceute the code using the terminal. The program will wait for a connection from the simulator, you will see "Server is now listening..."
2. Click the 'Fly!' icon in the simulator flight in the bottom left corner and wait for the simulator to load. It will connect to the interpreter in the meantime.

The code is designed to read line after line of commands entered in a terminal from the user once the program has started running. 

3. In the terminal, run te foolowing command:
g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread

and then:
./a.out fly.txt

## Interpreter code structure
openDataServer(5400)
connectControlClient("127.0.0.1",5402)
var warp -> sim("/sim/time/warp")
var magnetos -> sim("/controls/switches/magnetos")
var throttle -> sim("/controls/engines/current-engine/throttle")
var mixture -> sim("/controls/engines/current-engine/mixture")
var masterbat -> sim("/controls/switches/master-bat")
var masterlat -> sim("/controls/switches/master-alt")
var masteravionics -> sim("/controls/switches/master-avionics")
var brakeparking -> sim("/sim/model/c172p/brake-parking")
var primer -> sim("/controls/engines/engine/primer")
var starter -> sim("/controls/switches/starter")
var autostart -> sim("/engines/active-engine/auto-start")
var breaks -> sim("/controls/flight/speedbrake")
var heading <- sim("/instrumentation/heading-indicator/offset-deg")
var airspeed <- sim("/instrumentation/airspeed-indicator/indicated-speed-kt")
var roll <- sim("/instrumentation/attitude-indicator/indicated-roll-deg")
var pitch <- sim("/instrumentation/attitude-indicator/internal-pitch-deg")
var rudder -> sim("/controls/flight/rudder")
var aileron -> sim("/controls/flight/aileron")
var elevator -> sim("/controls/flight/elevator")
var alt <- sim("/instrumentation/altimeter/indicated-altitude-ft")
var rpm <- sim("/engines/engine/rpm")
Print("waiting 2 minutes for gui")
Sleep(120000)
Print("let's start")
warp = 32000
Sleep(1000)
magnetos = 3
throttle = 0.2
mixture = 0.949
masterbat = 1
masterlat = 1
masteravionics = 1
brakeparking = 0
primer = 3
starter = 1
autostart = 1
Print("engine is warming...")
Print(rpm)
while rpm <= 750 {
	Print(rpm)
}
Sleep(5000)
Print("let's fly")
var h0 = heading
breaks = 0
throttle = 1
while alt < 1000 {
	rudder = (h0 - heading)/80
	aileron = -roll / 70
	elevator = pitch / 50
	Sleep(250)
}
Print("done")




