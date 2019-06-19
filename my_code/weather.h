#ifndef WEATHER_H
#define WEATHER_H

#include <string>
#include <vector>
#include "date.h"

class Image {
public:
    Image(int, int, std::string);
    // copy constructor:
    Image(const Image&);
    ~Image();
    Image& operator=(const Image&);
    int image_sz();
    
    /*
     * Setting `display() = 0` here makes this an abstract
     * class that can't be implemented.
     * */
    virtual void display() const;
    /*
     * If we don't want virtual method lookup, we
     * could just declare:
     * void display();
     * */
    
    int get_height() const { return height; }
    int get_width() const { return width; }
    
private:
    int width;
    int height;
    std::string filename;
    char* image_buf;
    void copy_fields(const Image&);
};

class Png : public Image {
public:
    Png(int, int, std::string);
    
    void display() const;
};

class Gif : public Image {
public:
    Gif(int, int, std::string);
    
    void display() const;
};

class Jpeg : public Image {
public:
    Jpeg(int, int, std::string);
    
    void display() const;
    
private:
    int quality;
};

struct GPS {
    double latitude;
    double longitude;
    GPS(double la, double lo) : latitude(la),
        longitude(lo) {}
};

std::ostream& operator<<(std::ostream& os, const GPS& gps);

class Date;

class WReading {
    friend std::ostream& operator<<(std::ostream& os, const WReading& wr);
 public:
    WReading(Date dt, double temp, double hum, double ws, Image* img);
    double get_heat_index() const;
    double get_wind_chill() const;
    double get_tempF() const;
    double get_tempC() const;
    void display_img() const; 

 private:
    Date date;
    double temperature;  // stored temp in C
    double humidity;
    double windspeed;
    Image* img;
};


const int UNRATED = -1;
const int BAD = 0;
const int OK = 1;
const int GOOD = 2;

class Weather {
    // << should output name, rating, and use the GPS << to output my_loc
    friend std::ostream& operator<<(std::ostream& os, const Weather& w);
 public:
    Weather(std::string nm, GPS loc);
    std::string get_name() const;
    int get_rating() const;
    void set_rating(int new_rating);
    void add_reading(WReading wr);
    void display_images(); 
 private:
    std::vector<WReading> wreadings;
    std::string station_nm;
    GPS my_loc;
    int rating = UNRATED;
};


#endif
