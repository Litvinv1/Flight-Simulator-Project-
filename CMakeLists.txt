cmake_minimum_required(VERSION 3.15)
project(ex3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
add_executable(ex3 main.cpp lexer.cpp lexer.h Command.h OpenServerCommand.cpp OpenServerCommand.h ConnectCommand.cpp ConnectCommand.h DefineVarCommand.cpp DefineVarCommand.h simulatorFlightObject.cpp simulatorFlightObject.h AssignCommand.cpp AssignCommand.h PrintCommand.cpp PrintCommand.h SleepCommand.cpp SleepCommand.h ConditionParser.cpp ConditionParser.h LoopCommand.cpp LoopCommand.h symbolTables.cpp symbolTables.h IfCommand.cpp IfCommand.h BinaryOperator.h Div.h ex1.h Interpreter.h Minus.h Mul.h Plus.h UMinus.h UnaryOperator.h UPlus.h Value.h Variable.h BinaryOperator.cpp Div.cpp ex1.cpp Expression.cpp Interpreter.cpp Minus.cpp Mul.cpp Plus.cpp UMinus.cpp UnaryOperator.cpp UPlus.cpp Value.cpp Variable.cpp Expression.h)