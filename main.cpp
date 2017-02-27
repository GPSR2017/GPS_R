
#include "GPS_R.h"
#include <fstream>

int main ( int argc, char* argv[] ) {
    vector<string> inputArgs;
    for ( int i=1; i<argc; ++i )
        inputArgs.emplace_back(argv[i]);
    
    ofstream log_file;
    
    log_file.open("GPS_R.log");
    setup_log(log_file);
    
    
    for ( auto iter = inputArgs.begin(); iter != inputArgs.end(); ++iter )
        cout << (*iter) << endl;
    
    arg_check( inputArgs );
    
    //argument_parse(argc,argv);
    prototypes();
    return 0;
}
