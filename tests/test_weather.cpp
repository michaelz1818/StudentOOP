#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include "../my_code/weather.h"
#include "../my_code/date.h"

using namespace std;

void get_wreadings(string filenm, Weather& w) {
    ifstream rfile(filenm);
    while (!rfile) {
        cerr << "Could not read input file " << filenm << endl;
        rfile.clear();
        cout << "Please check your file name and input again: " << endl;
        cin >> filenm;
        rfile.open(filenm); 
    }
    int m, d, y;
    double temp, hum, ws;
    while (rfile >> m >> d >> y >> temp >> hum >> ws) {
        WReading wr = WReading(Date(d, m, y), temp, hum, ws);
        w.add_reading(wr);
    }
    rfile.close();
}


int main() {
    Weather irkutsk = Weather("Irkutsk", GPS(46.3, 67.2));

    string filenm;
    cout << "Input the name of the new readings file:\n";
    cin >> filenm;

    get_wreadings(filenm, irkutsk);

    cout << irkutsk << endl;
}
