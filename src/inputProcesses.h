/**
 *  @brief  Header file for the input processes.
 *  @author Peter Matheny
 */

#ifndef INPUTPROCESSES_H
#define INPUTPROCESSES_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <iomanip>

using namespace std;

vector<string> arg_check( const vector<string> &inputArgs );

void help_text();

void setup_log(ofstream &logFile);

vector<string> argument_parse( string input_file, ofstream &logFile );

void remove_spaces ( string & s );

string grab_value ( const string &s );

void log_header(ofstream &logFile);

void append2log(ofstream &logFile, string s);

#endif // INPUTPROCESSES_H
