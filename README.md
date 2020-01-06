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
## Command-
The Command class is a interface class that contain execute function that we will run for all the command class.
# OpenServerCommand-
This command class opens a thread in which we open and run such as server. Our simulator connects to the server as client and sends requests. Each requests contain the values of the airplane. Our server accepts the requests and updates the database accordingly.
## ConnectCommand-
This command class opens a thread in which we open and run such a client. We act as a client who sends requests to the simulator. Every time we get a new command for the simulator from the code we are sending it to the simulator as a request through this client.
## Lexer-
This class is reading the fly.text and return the commands into the file split.
## Variables- 
we can assign variables to only get data from the simulator using <-, or also update their value inside the simulator using ->.
We can also assign local variables that aren't connected to the simulator itself using regular var x = 'value'. 
Every variable declaration has to start with the var keyword.
## Print-
We use the keyword Print(variable or string value) to print something to the screen.
## Sleep-
we use the keyword Sleep(integer value) to make the main thread sleep for the requested amount of time in milliseconds.
## While loop-
Declare a while loop by calling while e1 [condition] e2 { loop content }
## If loop-
Declare an if condition by calling if e1 [condition] e2 { if content }


## More 
github link- 


