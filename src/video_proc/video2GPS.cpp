/**
 *  @brief  Contains routines used in extracting the video GPS data.
 *  @author Peter Matheny
 *
 *  Currently it does not use OCR on stills from the video, instead
 *  it reads input from a file defined in the parameters.in file.
 */

#include "video2GPS.h"

using namespace std;

/**
 *  @brief  Reads the file containing the OCR results.
 */
set<videoFrame> readOCR ( string ocrName ) {
    cout << "Parsing input..." << endl;
    int validlines ( 0 ), nlines ( 0 );
    set<videoFrame> vidData;
    vector<videoFrame> deleteMe;
    videoFrame vid;
    vector<string> OCRresults;
    ifstream inFile;
    string   line;
    string   valid_line;
    string  front ( "GARMIN" );
    inFile.open ( ocrName.c_str() );

    while ( getline ( inFile, line ) ) {
        nlines++;

        if ( line.find ( front ) != string::npos ) {
            vid = parseVideoLine ( line );
            vid.setepoch();

            if ( vid.bad == 0 && vid.checkVals() ) {
                validlines++;
                vidData.insert ( vid );
            }
        }
    }

    inFile.close();

    cout << "Read in " << validlines << " valid lines out of " << nlines << endl;
    helpme ( vidData );
    return vidData;
}

/**
 *  @brief  Splits the line into the desired values.
 */
videoFrame parseVideoLine ( string& line ) {
    int setSucess ( 1 ), epochSucess ( 1 );
    vector<string> broken_line;
    videoFrame vid;
    string strip1;
    broken_line = stripString ( line );

    if ( broken_line.size() == 6 ) {
        setSucess = vid.set_values ( broken_line[1], broken_line[2], broken_line[3],
                                     broken_line[4] );
        epochSucess = vid.setepoch();
    }

    if ( setSucess != 0 || epochSucess != 0 ) {
        vid.bad = -1;
    }

    return vid;
}

/**
 *  @brief Debug function with vectors.
 */
void helpme ( vector<string>& v ) {
    cout << "Size: " << v.size() << endl;

    for ( auto iter = v.begin(); iter != v.end(); ++iter ) {
        cout << *iter << endl;
    }
}

void helpme ( set<videoFrame>& s ) {
    cout << "Unique Values: " << s.size() << endl;

    for ( auto iter = s.begin(); iter != s.end(); ++iter ) {
        cout << *iter << endl;
    }
}

/**
 *  @brief Returns a vector containing the values in each line.
 *
 *  The values are split by a space.  No error handling goes into
 *  this routine.
 */
vector<string> stripString ( string& s ) {
    vector<string> results;
    int nextspace_pos ( 1 );
    string tmp = s;

    while ( tmp.find ( ' ' ) != string::npos ) {
        nextspace_pos = tmp.find ( ' ' );
        results.push_back ( tmp.substr ( 0, nextspace_pos ) );
        tmp = ( tmp.substr ( nextspace_pos + 1, tmp.size() - 1 ) );
    }

    return results;
}

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
    regex dateCheck ( "[0-9]{2}/[0-9]{2}/[0-9]{4}" );
    regex timeCheck ( "[0-9]{2}:[0-9]{2}:[0-9]{2}" );
    regex latCheck ( "[NS][0-9]{3}\\.[0-9]{5}" );
    regex lonCheck ( "[WE][0-9]{3}\\.[0-9]{5}" );
    valid = ( regex_match ( date, dateCheck ) && regex_match ( time, timeCheck )
              && regex_match ( lat, latCheck ) && regex_match ( lon, lonCheck ) );
    return valid;
}

