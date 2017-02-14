/**

File for a function that will take locate the depth in the GPR file and assign
it the value of GPR_depth

**/

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
    cout<<"The GPR_depth file has compiled.\n";
}
