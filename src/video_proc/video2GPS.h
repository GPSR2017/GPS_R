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
#include <set>
#include "videoFrame.h"

/**
 *  @class  videoFrame
 *  @brief  Stores data related to GPS from the video.
 *  
 *  Saves the time, lattitude and longitude as read from
 *  a still of the video.  There are a few helper functions
 *  that are used to guard the values from uninteded problems.
 */
using namespace std;

int video2GPS ();

set<videoFrame> readOCR ( std::string ocrName );

videoFrame parseVideoLine( std::string &line );

vector<string> stripString(string &s);

void helpme( vector<string> &v);

void helpme( set<videoFrame> &s);

#endif // VIDEO_H
