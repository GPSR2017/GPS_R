#include "inputs.h"

int arg_check( const std::vector<string> &inputArgs ) {
    cout <<"Checking arguments...\n";
    
    if ( inputArgs.empty() ) {
        cout << "\nNo input arguments, exiting\n\n"
                "Usage: GPS_R <input_parameters_file> [logfile]\n\n";
    }
    
    if ( inputArgs.size() == 1 ) {
        cout << "Reading in " << inputArgs[0] 
             << "\nNo log file specified, using "
                "default GPS_R.log\n";
        
        ofstream logFile;
        string log_name("GPS_R.log");
        logFile.open(log_name);
        setup_log(logFile);
        argument_parse( inputArgs[0], logFile);
    }
    
    if ( inputArgs.size() == 2 ) {
        cout << "Reading in " << inputArgs[0] 
             << "\nUsing log file: "
             << inputArgs[1] << endl;
        ofstream logFile;
        logFile.open(inputArgs[1]);
        setup_log(logFile);
        argument_parse( inputArgs[0], logFile);
    }
    
    if ( inputArgs.size() > 2 ) {
        cout << "Too many arguments\n"
                "Usage: GPS_R <input_parameters_file> [logfile]\n\n";
        return 1;
    }
    return 0;
}
