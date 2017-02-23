/**
 *
 * File containing the function prototypes.
 *
*/

#include <string>
#include <iostream>

struct measurement {
    float time;
    float lat;
    float lon;
    float GPR_depth;
};

struct videoFrame {
    float time;
    float lat;
    float lon;
};

struct GPREntry {
    float time;
    float depth;
};

videoFrame video2GPS (int frame_number);

float* inputVideo (std::string videoFilename);

measurement correlateTimes (videoFrame vid_frame, GPREntry GPR_data);

/// A function that will read and convert the time from the .csv GPR data file
measurement readGPRTime (float GPRTime );

/// A function that will convert the time found in the GPR file into a real time
/// corresponding to the video file
measurement convertGPRTime ( measurement time);

/// A function that will read the GPR depth in the .csv GPR data file
measurement readGPRDepth ( measurement GPR_Depth );

/// Functions that will read latitude and longitude from GPR file
measurement readGPRLat ( measurement lat );
measurement readGPRLon ( measurement lon);

int main() {
    std::cout<<"The prototypes have compiled.\n";
}
