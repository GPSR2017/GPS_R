#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>

class videoFrame {
    private:
        float time;
        float lat;
        float lon;
    public:
        void print();
        void set_values(float,float,float);
};

videoFrame video2GPS (int frame_number);

#endif // VIDEO_H
