/**
 *  @brief      Collection of functions used to parse the input
 *              file.
 *  @author     Peter Matheny
 *
 */

#include "inputProcesses.h"


int argument_parse ( string input_file, ofstream& logFile ) {

    ifstream      inFile;
    string        infile;
    string        outfile;
    string        line;
    set<string>   valid_vars{"infile", "outfile"};
    set<string>   inVars;

    inFile.open ( input_file.c_str() );

    /** Parse inputfile for variables to define. */
    while ( getline ( inFile, line ) ) {
        /**Check for =  */
        if ( line.find ( '=' ) != string::npos ) {
            inVars.insert ( line );
        }
    }

    inFile.close();

    /** Check if the variable is in the list of variables & assign them. */
    for ( auto iter = inVars.begin(); iter != inVars.end(); ++iter ) {
        if ( ( *iter ).find ( "infile" ) != string::npos ) {
            infile = grab_value ( *iter );

        } else if ( ( *iter ).find ( "outfile" ) != string::npos ) {
            outfile = grab_value ( *iter );
        }
    }

    cout << "infile = " << infile << endl;
    cout << "outfile = " << outfile << endl;
    append2log ( logFile, "Input Parameters" );
    append2log ( logFile, "infile = " + infile );
    append2log ( logFile, "outfile = " + outfile );
    return 0;
}

/**
 *  @brief  Removes spaces from a string.
 *
 *  Runs recursively through the string removing any spaces.
 */

void remove_spaces ( string& s ) {

    int space_pos;

    space_pos = s.find ( ' ' );

    if ( space_pos == -1 ) {
        return;
    }

    s.erase ( space_pos, 1 );

    remove_spaces ( s );
}

/**
 *  @brief  Reads strings after = sign.
 *
 *  Used in reading the parameters.in file so that the
 *  value to the right of the = sign is read into the program.
 */

string grab_value ( const string& s ) {

    int     equal_pos = s.find ( '=' );

    string  tmpVal ( s.substr ( equal_pos + 1, s.size() - 1 ) );
    remove_spaces ( tmpVal );

    return tmpVal;
}

/**
 *  @brief  Parses input and delegates to relevant functions.
 *
 *  Here is where the error handling takes place for the input
 *  arguments.  The first argument is required however the second
 *  is not and will be set to a default value if not defined.
 */

int arg_check ( const std::vector<string>& inputArgs ) {

    cout << "Checking arguments...\n";

    /** Sanity check */
    if ( ( inputArgs.empty() ) || ( inputArgs.size() > 2 ) ) {

        cout << "\nError with inputs, exiting\n\n";

        help_text();
        return 1;
    }

    ofstream logFile;
    string log_name;

    if ( inputArgs.size() == 1 ) {

        log_name = "GPS_R.log";

        cout << "Reading in " << log_name
             << "\nNo log file specified, using "
             "default GPS_R.log\n";
    }

    if ( inputArgs.size() == 2 ) {

        log_name = inputArgs[1];

        cout << "Reading in " << log_name
             << "\nUsing log file: "
             << log_name << endl;
    }

    logFile.open ( log_name );
    setup_log ( logFile );
    argument_parse ( inputArgs[0], logFile );

    return 0;
}

/**
 *  @brief  Repeated help text goes here.
 */

void help_text() {
    cout << "\n\nUsage: GPS_R <input_parameters_file> [logfile]\n\n";
}

/**
 *  @brief  Sets up the log here.
 */

void setup_log ( ofstream& logFile ) {
    log_header ( logFile );
}

/**
 *  @brief  Adds a header to the log file.
 */

void log_header ( ofstream& logFile ) {
    logFile << setw ( 30 ) << setfill ( '*' ) << '\n'
            << setfill ( ' ' )
            << "\nGPS_R Project Log\n\n"
            << setw ( 30 ) << setfill ( '*' ) << "\n\n";
}

/**
 *  @brief  Appends strings to the log file.
 */

void append2log ( ofstream& logFile, string s ) {
    logFile << s << endl;
}
