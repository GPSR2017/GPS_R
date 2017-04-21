// Program that will convert the char ','  into strings seperated by  "\n"

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    fstream inputFile;
    fstream outfile("GPRHold.txt", ios::out);
    string data;

    inputFile.open("GPRdata.csv", ios::in);

    while(inputFile >> data)
        outfile << data ;
        
    replace( data.begin(), data.end(), ',' , '\n');

    outfile << data;

    return 0;
}
