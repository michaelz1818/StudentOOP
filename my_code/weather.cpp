#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

/*
 * A constructor for weather class.
 * */
Weather::Weather(std::string nm, GPS loc):
station_nm(nm), my_loc(loc) {
}

ostream& operator<<(ostream& os, const GPS& gps){
    os << "(" << gps.latitude << "," << gps.longitude << ")";
    return os;
}

ostream& operator<<(ostream& os, const Weather& w){
    os << "Name: " << w.station_nm << ", Location: " << w.my_loc << ", Rating: " << w.rating << endl;
    return os;
}

int Weather::get_rating() const {
    return rating;
}

void Weather::set_rating(int new_rating){
    rating = new_rating; 
}

string Weather::get_name() const {
    return station_nm;
}
