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

