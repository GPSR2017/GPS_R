# Makefile for GPS_R project for use on linux.
#
# Have to use CXX for c++ compiling, CC is made
# for compiling C
#

program_CXX_SRCS := $(wildcard *.cpp)
program_CXX_OBJS := ${program_CXX_SRCS:.cpp=.o} 
program_OBJS := $(program_CXX_OBJS)
$(info $$var is [${program_OBJS}])

CXXFLAGS += -Wall -std=c++0x
#phony means that these aren't actually files.
.PHONY: all clean cleanall distclean

all : $(program_OBJS)

#Compile everything into object files.
#The variable $(COMPILE.cc) is built into make.
$(program_OBJS): $(program_CXX_SRCS)
	$(COMPILE.cc) $(program_CXX_SRCS)

#The @ means don't announce the command, - means don't display errors
clean :
	@- $(RM) $(program_OBJS)

cleanall :
	@- $(RM) $(program_OBJS)

distclean :
	@- $(RM) $(program_OBJS)

