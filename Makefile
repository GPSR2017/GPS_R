#Makefile for GPS_R project for use on linux.

CC     = g++
CFLAGS = -Wall

all: prototypes

prototypes: prototypes.o
	${CC} ${CFLAGS} -o prototypes.o prototypes.cpp

clean:
	rm -rf prototypes.o
