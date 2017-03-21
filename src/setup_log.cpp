#include "inputs.h"

void setup_log(ofstream &logFile) {
    log_header(logFile);
}

void log_header(ofstream &logFile) {
    logFile << setw(30) << setfill('*') << '\n'
            << setfill(' ')
            << "\nGPS_R Project Log\n\n"
            << setw(30) << setfill('*') << "\n\n";
}

void append2log(ofstream &logFile, string s) {
    logFile << s << endl;
}
