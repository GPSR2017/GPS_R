#ifndef ARG_CHECK_H
#define ARG_CHECK_H

#include <iostream>
#include <fstream>
#include <vector>
#include "argument_parse.h"

using namespace std;

int arg_check( const std::vector<string> &inputArgs );

void setup_log(ofstream &logFile);

#endif
