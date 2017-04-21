/**
 *  @brief  Header for the video2GPS source.
 *  @author Peter Matheny
 *
 */

#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <set>
#include <regex>

/**
 *  @class  videoFrame
 *  @brief  Stores data related to GPS from the video.
 *  
 *  Saves the time, lattitude and longitude as read from
 *  a still of the video.  There are a few helper functions
 *  that are used to guard the values from uninteded problems.
 */
using namespace std;

class videoFrame {
    private:
        string date;
        string time;
        string lat;
        string lon;
        time_t epoch;
        bool valid;
    public:
        int bad = 0;
        void print();
        int set_values(string, string, string, string);
        int setepoch();
        bool checkVals();
        bool operator< (const videoFrame& v) const;
        bool operator> (const videoFrame& v) const;
        friend ostream &operator<<( ostream &output, const videoFrame &v) {
            output << "Date: " << v.date << ", Time: " << v.time << ", Lat: " << v.lat << ", Lon:" << v.lon;
            return output;
        }
};

int video2GPS ();

set<videoFrame> readOCR ( std::string ocrName );

videoFrame parseVideoLine( std::string &line );

vector<string> stripString(string &s);

void helpme( vector<string> &v);

void helpme( set<videoFrame> &s);

#endif // VIDEO_H
