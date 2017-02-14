#Makefile for GPS_R project for use on linux.

CC     = g++
CFLAGS = -Wall

all : prototypes arg_parser

prototypes : prototypes.o
	${CC} ${CFLAGS} -o prototypes.o prototypes.cpp

arg_parser : argument_parse.o
	${CC} ${CFLAGS} -o argument_parse.o argument_parse.cpp

clean :
	rm -rf *.o
