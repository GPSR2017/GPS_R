#ifndef ARGUMENT_PARSE_H
#define ARGUMENT_PARSE_H

#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int argument_parse( int argc, char *argv[] );

void remove_spaces ( string & s );

string grab_value ( const string &s );

#endif
