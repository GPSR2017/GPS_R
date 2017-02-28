
#include "GPS_R.h"
#include <fstream>

int main ( int argc, char* argv[] ) {
    vector<string> inputArgs;
    for ( int i=1; i<argc; ++i )
        inputArgs.emplace_back(argv[i]);
    
    for ( auto iter = inputArgs.begin(); iter != inputArgs.end(); ++iter )
        cout << (*iter) << endl;
    
    arg_check( inputArgs );
    
    prototypes();
    return 0;
}
