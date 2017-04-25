#include "videoFrame.h"

/**
 *  @brief  Formatted printing for videoFrame.
 */
void videoFrame::print() {
    cout << "Date: " << date << ", Time: " << time << ", Lat: " << lat << ", Lon:"
         << lon << endl;
}

/**
 *  @brief  Sets the parameters of the videoFrame.
 *
 *  Includes error handling for the variable assignment.
 */
int videoFrame::set_values ( string d, string t, string latitude,
                             string longitude ) {
    // Add guards here.
    bool error;
    error = ( d.size() != 10 || t.size() != 8 || latitude.size() != 10
              || longitude.size() != 10 );

    if ( error ) {
        //cout << "Invalid input, check them with the helpme function." <<endl;
        return 1;
    }

    date = d;
    time = t;
    lat = latitude;
    lon = longitude;
    this->checkVals();
    return 0;
}

/**
 *  @brief Sets up the date information so that it can later be compared.
 */
int videoFrame::setepoch() {
    char* err;
    struct tm tm;
    err = strptime ( ( date + " " + time ).c_str(), "%m/%d/%Y %H:%M:%S", &tm );

    if ( !err ) {
        //cout << "Could not read date information." <<endl;
        return 1;
    }

    epoch = mktime ( &tm );
    return 0;
}

/**
 *  @brief Needed to place into an STL set.
 */
bool videoFrame::operator< ( const videoFrame& v ) const {
    if ( epoch < v.epoch ) {
        return true;

    } else {
        return false;
    }
}

/**
 *  @brief Needed to place into an STL set.
 */
bool videoFrame::operator> ( const videoFrame& v ) const {
    if ( epoch > v.epoch ) {
        return true;

    } else {
        return false;
    }
}

bool videoFrame::checkVals() {
    regex dateCheck ( "[0-9]{2}/[0-9]{2}/20[0-9]{2}" );
    regex timeCheck ( "[0-9]{2}:[0-9]{2}:[0-9]{2}" );
    regex latCheck ( "[NS][0-9]{3}\\.[0-9]{5}" );
    regex lonCheck ( "[WE][0-9]{3}\\.[0-9]{5}" );
    valid = ( regex_match ( date, dateCheck ) && regex_match ( time, timeCheck )
              && regex_match ( lat, latCheck ) && regex_match ( lon, lonCheck ) );
    return valid;
}

