#include "video2GPS.h"

using namespace std;

videoFrame video2GPS ( int frame_number ) {
    videoFrame vid;
    vid.set_values ( 10.0, 10000, 10000 );
    vid.print();
    return vid;
}

void videoFrame::print() {
    cout << "Time: " << time << ", Lat: " << lat << ", Lon:" << lon << endl;
}

void videoFrame::set_values ( float t, float latitude, float longitude ) {
    time = t;
    lat = latitude;
    lon = longitude;
}
