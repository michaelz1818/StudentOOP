#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "weather.h"
#include "date.h"

using namespace std;

const double F_TO_C = 5 / 9;
const double C_TO_F = 9 / 5;

Image::Image(int w, int h, std::string flnm)
: width(w), height(h)
{
    filename = flnm;
    image_buf = new char[image_sz()];
}

// copy constructor:
Image::Image(const Image& rhs) {
    copy_fields(rhs); 
}

Image::~Image() {
    if(image_buf != nullptr){
        delete [] image_buf;
    }
}

Image& Image::operator=(const Image& rhs) {
    if(this != &rhs){
        if(image_buf != nullptr){
            delete [] image_buf;
        }
        copy_fields(rhs);
    }
    return *this;
}

int Image::image_sz() {
    return width * height;
}


void Image::copy_fields(const Image& rhs) {
    width = rhs.width;
    height = rhs.height;
    filename = rhs.filename;
    image_buf = new char[image_sz()]; //note image_sz() should be after weight and height being reissued 
    *image_buf = *rhs.image_buf;
}


/*
 * Setting `display() = 0` here makes this an abstract
 * class that can't be implemented.
 * */
string Image::display(std::string s) {
    return "Displaying image " + s;
}


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
    return (temperature * C_TO_F) + 32;
}

double WReading::get_tempC() const {
    return temperature;
}

