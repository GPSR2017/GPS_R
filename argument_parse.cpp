/*
 * Argument parser, checks file for expected variables and reads
 * them into the program.  Also creates a log file documenting the
 * inputs.
 *
 */
 
#include "argument_parse.h"

int check_args( int &argc, char *argv[] );

ofstream setup_log( int &check_return, char *argv[]);

void arg_parse_help( int &check_return);

int argument_parse( int argc, char *argv[] ) {

    //Initialize variables.
    ifstream      inFile;
    ofstream      logFile;
    string        infile;
    string        outfile;
    string        line;
    set<string>   valid_vars{"infile", "outfile"};
    set<string>   inVars;
    int           arg_check;
    arg_check = check_args( argc, argv );
    //Define variables.
    inFile.open   (argv[1]);
    logFile = setup_log( arg_check, argv );

    //Parse inputfile for variables to define.
    while(getline(inFile, line)) {
        //Check for =
        if ( line.find('=') != string::npos ) {
            inVars.insert(line);
        }
    }
    inFile.close();

    //Remove bad input variables.

    //Check if the variable is in the list of variables & assign them.
    for (auto iter = inVars.begin(); iter != inVars.end(); ++iter) {
        if ( (*iter).find("infile") != string::npos )
            infile = grab_value(*iter);
        else if ( (*iter).find("outfile") != string::npos )
            outfile = grab_value(*iter);
    }
    //Make the printing into a function.
    cout << "outfile = " << outfile << endl;
    cout << "infile = " << infile << endl;
    //Write what was done in logfile - need to include a header for the logfile.
    logFile << "outfile = " << outfile << endl;
    logFile << "infile = " << infile << endl;
    logFile.close();
    
    return 0;
}

int check_args( int &argc, char *argv[] ) {
    for ( int i(0); i < argc ; ++i ) {
        cout << argv[i] << endl;
    }
    if ( argc < 2 ) return 1;
    if ( argc == 2 ) return 2;
    if ( argc == 3 ) return 3;
    return 0;
}

ofstream setup_log( int &check_return, char *argv[]) {
    if ( check_return == 2 ) {
        cout << "No log file specified, using default GPS_R.log" << endl;
        ofstream logFile;
        logFile.open("GPS_R.log");
        return logFile;
    }
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


