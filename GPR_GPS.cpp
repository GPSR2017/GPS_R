/**

File that will be used to create the the function that will read lat and lon
from the GPR csv file.

**/

#include <string>
#include <iostream>

using namespace std;

struct measurement{
    float time;
    float lat;
    float lon;
    float GPR_depth;
};

struct GPREntry{
    float time;
    float depth;
};

int main()
{
    cout<<"The GPR_GPS file has compiled.\n";
}
