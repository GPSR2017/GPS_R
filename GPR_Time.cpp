/**

File that will read the time data from the GPR data and then convert it into
real time that correlates to the GPS data. It will list the time as the float
time

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
    cout<<"The GPR_Time file has compiled.\n";
}
