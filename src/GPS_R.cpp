/**
 *  @brief      Combines GPS and GPR data.
 *  @author     Peter Matheny
 *  @author     Colton Baker
 *  @date       2017-
 *  @param[in]  parameters  Determines IO locations
 *  @param[in]  logfile     (Optional) Logfile name.
 */

#include <fstream>
#include "GPS_R.h"

int main ( int argc, char* argv[] ) {

    vector<string>  inputArgs;
    vector<string>  check_args;

    for ( int i = 1; i < argc; ++i ) {
        inputArgs.emplace_back ( argv[i] );
    }

    check_args = arg_check ( inputArgs );

    if ( check_args.size() == 0 ) {
        cout << "Exiting program\n";
        return 1;
    }
    
    readOCR(check_args[0]);
    
    return 0;
}
