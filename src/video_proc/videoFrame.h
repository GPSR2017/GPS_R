#ifndef VIDEOFRAME_H
#define VIDEOFRAME_H

#include <string>
#include <iostream>
#include <ctime>
#include <regex>

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

#endif //VIDEOFRAME_H
