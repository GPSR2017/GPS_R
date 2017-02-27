#ifndef ARGUMENT_PARSE_H
#define ARGUMENT_PARSE_H

#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int argument_parse( string input_file, string log_file );

void remove_spaces ( string & s );

string grab_value ( const string &s );

#endif
