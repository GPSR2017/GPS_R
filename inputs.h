#ifndef INPUTS_H
#define INPUTS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <iomanip>

using namespace std;

int arg_check( const std::vector<string> &inputArgs );

void setup_log(ofstream &logFile);

int argument_parse( string input_file, ofstream &logFile );

void remove_spaces ( string & s );

string grab_value ( const string &s );

void log_header(ofstream &logFile);

void append2log(ofstream &logFile, string s);

#endif
