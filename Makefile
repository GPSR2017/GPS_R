# Makefile for GPS_R project for use on linux.
#
# Have to use CXX for c++ compiling, CC is made 
# for compiling C
#

CPP      = g++
CPPFLAGS = -Wall -std=c++0x

all : prototypes arg_parser

prototypes : prototypes.o
	${CPP} ${CPPFLAGS} -o prototypes.o prototypes.cpp

arg_parser : argument_parse.o
	${CPP} ${CPPFLAGS} -o argument_parse.o argument_parse.cpp

clean :
	rm -rf *.o
