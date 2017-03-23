/*
 *  \brief     Combines GPS and GPR data.
 *  \author    Peter Matheny
 *  \author    Colton Baker
 *  \date      2017-
 */


#include "GPS_R.h"
#include <fstream>

int main ( int argc, char* argv[] ) {

    vector<string>  inputArgs;
    int             check_args;

    for ( int i=1; i<argc; ++i )
        inputArgs.emplace_back( argv[i] );

    check_args=arg_check( inputArgs );

    if ( check_args == 1 ) {
        cout << "Exiting program\n";
        return 1;
    }

    video2GPS( 10 );
    prototypes();

    return 0;
}
