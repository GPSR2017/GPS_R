# Makefile for GPS_R project for use on linux.
#
# Have to use CXX for c++ compiling, CC is made
# for compiling C
#

CPP      = g++
CPPFLAGS = -Wall -std=c++0x

all : prototypes arg_parser main

prototypes : prototypes.cpp
	${CPP} ${CPPFLAGS} -c prototypes.cpp

arg_parser : argument_parse.cpp
	${CPP} ${CPPFLAGS} -c argument_parse.cpp

main : prototypes.o argument_parse.o
	${CPP} ${CPPFLAGS} -o GPS_R prototypes.o argument_parse.o main.cpp

clean :
	rm -f *.o

cleanall :
	rm -f GPS_R *.o
