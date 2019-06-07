#include <iostream>
#include <string>
#include <vector>
#include "weather.h"
#include "date.h"

using namespace std;

/*
 * A constructor for weather class.
 * */
WReading::WReading(Date dt, double temp, double hum, double ws) :
date(dt), temperature(temp), humidity(hum), windspeed(ws) {}

Weather::Weather(std::string nm, GPS loc):
station_nm(nm), my_loc(loc) {}

ostream& operator<<(ostream& os, const GPS& gps){
    os << "(" << gps.latitude << "," << gps.longitude << ")";
    return os;
}

ostream& operator<<(ostream& os, const Weather& w){
    os << "Name: " << w.station_nm << ", Location: " << w.my_loc << ", Rating: " << w.rating << endl;
    for(WReading aReading : w.wreadings){
        os << aReading;
    }
    return os;
}

ostream& operator<<(ostream& os, const WReading& wr){
    os << "Date: " << wr.date << ", Humidity: " << wr.humidity << ", Temperature: " << wr.temperature << ", Windspeed: " << wr.windspeed << endl;
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

void Weather::add_reading(WReading wr){
    wreadings.push_back(wr); 
}
