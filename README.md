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





