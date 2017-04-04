/**
 *
 * Conversion file to convert the GPR collected time in the .csv file into
 * seconds starting at 0. Time is currently tracked by computer time, which does
 * not start over each time that data is collected. This function will only take
 * care of the first conversion into seconds. ConvertGPRTime2 will take care of
 * all conversions after the first one of the file.
 *
*/

#include <string>
#include <iostream>
using namespace std;

int main()
{
    GPRTime = GPRTime - GPRTime + 1;

    cout<<"GPRTime = " << GPRTime << endl;

    return 0;
}
