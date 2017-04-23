/**
*  @brief   Header file for the .csv Reader
*  @author  Colton Baker
*/

#ifndef EXCELREADER_H
#define EXCELREADER_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

/**
*  @class  excelData
*  @brief  Stores the data obtained from the .csv file
*
*  Saves the depthLayer1, depthLayer2, latitude, longitude and time from the .csv file.
*/

class excelData {
    private:
        string    depthLayer1;
        string    nameLayer1;
        string    depthLayer2;
        string    nameLayer2;
        string    latitude;
        string    longitude;
        string    time;
        bool      valid;
    public:
        int       bad = 0;
        int       values(string, string, string, string, string);
};

bool openFileIn ( fstream &, string )
;
