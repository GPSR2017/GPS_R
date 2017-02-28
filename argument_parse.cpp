/*
 * Argument parser, checks file for expected variables and reads
 * them into the program.  Also creates a log file documenting the
 * inputs.
 *
 */
 
#include "inputs.h"


int argument_parse( string input_file, ofstream &logFile ) {

    //Initialize variables.
    ifstream      inFile;
    string        infile;
    string        outfile;
    string        line;
    set<string>   valid_vars{"infile", "outfile"};
    set<string>   inVars;

    //Define variables.
    inFile.open   (input_file.c_str());

    //Parse inputfile for variables to define.
    while(getline(inFile, line)) {
        //Check for =
        if ( line.find('=') != string::npos ) {
            inVars.insert(line);
        }
    }
    inFile.close();

    //Remove bad input variables like stuff in comments.

    //Check if the variable is in the list of variables & assign them.
    for (auto iter = inVars.begin(); iter != inVars.end(); ++iter) {
        if ( (*iter).find("infile") != string::npos )
            infile = grab_value(*iter);
        else if ( (*iter).find("outfile") != string::npos )
            outfile = grab_value(*iter);
    }
    //Make the printing into a function.
    cout << "infile = " << infile << endl;
    cout << "outfile = " << outfile << endl;
    append2log(logFile, "Input Parameters");
    append2log(logFile, "infile = " + infile);
    append2log(logFile, "outfile = " + outfile);
    
    
    return 0;
}

void remove_spaces ( string & s ) {

    int space_pos;

    space_pos=s.find(' ');
    if ( space_pos == -1 )
        return;
    s.erase(space_pos,1);

    remove_spaces(s);
}

string grab_value ( const string &s ) {
    
    int     equal_pos = s.find('=');
    
    string  tmpVal(s.substr(equal_pos+1,s.size()-1));
    remove_spaces(tmpVal);
    
    return tmpVal;
}


