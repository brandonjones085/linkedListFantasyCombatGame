CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -pedantic-errors
CXXFLAGS += -Wall
LDFLAGS = -lboost_date_time
OBJS = main.o Vampire.o validateMenu.o validateInt.o validateChar.o teamOneMenu.o Queue.o Node.o Medusa.o HarryPotter.o Character.o BlueMen.o Barbarian.o Game.o menu.o
SRCS = main.cpp Vampire.cpp validateMenu.cpp validateInt.cpp validateChar.cpp teamOneMenu.cpp Queue.cpp Node.cpp Medusa.cpp HarryPotter.cpp Character.cpp BlueMen.cpp Barbarian.cpp Game.cpp menu.cpp
HEADERS =  Vampire.hpp validateMenu.hpp validateInt.hpp validateChar.hpp teamOneMenu.hpp Queue.hpp Node.hpp Medusa.hpp HarryPotter.hpp Character.hpp BlueMen.hpp Barbarian.hpp Game.hpp

main: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}:${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

.PHONY: clean


clean: 
	-rm ${OBJS} main
