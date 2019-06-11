#include <iostream>
#include <string>
#include <vector>
#include <cmath>
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

double WReading::get_heat_index() const {
    return -42.379 + 2.04901523 * get_tempF() + 10.14333127 * humidity - .22475541 * get_tempF() * humidity - .00683783 * get_tempF() * get_tempF() - .05481717 * humidity * humidity + .00122874* get_tempF() * get_tempF() * humidity + .00085282 * get_tempF() * humidity * humidity - .00000199* get_tempF() * get_tempF() * humidity * humidity;
}

double WReading::get_wind_chill() const {
    return 35.74 + (0.6215 * get_tempF()) - (35.75 * pow(windspeed, 0.16)) + (0.4275 * temperature * pow(windspeed, 0.16));
}

double WReading::get_tempF() const {
    return (temperature * 9 / 5) + 32;
}

double WReading::get_tempC() const {
    return temperature;
}
