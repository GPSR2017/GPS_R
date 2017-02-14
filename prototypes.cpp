/**

File containing the function prototypes.

**/
#include <string>
#include <iostream>
struct measurement{
    float time;
    float lat;
    float lon;
    float GPR_depth;
};

struct videoFrame{
    float time;
    float lat;
    float lon;
};

struct GPREntry{
    float time;
    float depth;
};

videoFrame video2GPS(int frame_number);

float* inputVideo(std::string videoFilename);

measurement correlateTimes(videoFrame vid_frame, GPREntry GPR_data);

int main()
{
    std::cout<<"The prototypes have compiled.\n";
}
