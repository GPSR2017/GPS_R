# Makefile for GPS_R project for use on linux.
#
# Have to use CXX for c++ compiling, CC is made
# for compiling C
#

program_NAME := GPS_R
CXXFLAGS += -Wall -std=c++0x
io_OBJS := $(wildcard src/*.cpp)
video_SRC := $(wildcard src/video_proc/*.cpp)
#excel_OBJS := $(wildcard src/excel_reader/*.cpp)
program_OBJS := $(io_OBJS:.cpp=.o)
program_OBJS += $(video_SRC:.cpp=.o)
#program_OBJS += $(excel_OBJS:.cpp=.o)
#phony means that these aren't actually files.
.PHONY: all clean cleanall distclean

all : $(program_NAME)

#Link the programs and compile
$(program_NAME): $(program_OBJS)
	$(LINK.cc) $(program_OBJS) -o $(program_NAME)

$(program_OBJS): $(program_SRC)
	$(MAKE) -C src
	$(MAKE) -C src/video_proc
	#$(MAKE) -C src/excel_reader

#The @ means don't announce the command, - means don't display errors
clean :
	@- $(RM) $(program_OBJS)
	@- $(RM) -r *~src\*~
	@- $(MAKE) clean -C src
	@- $(MAKE) clean -C src/video_proc
	@- $(MAKE) clean -C src/excel_reader

cleanall :
	@- $(RM) $(program_OBJS)
	@- $(RM) $(program_NAME)
	@- $(RM) -r html
	@- $(RM) -r *~src\*~
	@- $(RM) -rf latex
	@- $(MAKE) cleanall -C src
	@- $(MAKE) cleanall -C src/video_proc
	@- $(MAKE) cleanall -C src/excel_reader

distclean :
	@- $(RM) $(program_OBJS)
	@- $(RM) $(program_NAME)
	@- $(MAKE) distclean -C src
	@- $(MAKE) distclean -C src/video_proc
	@- $(MAKE) distclean -C src/excel_reader
