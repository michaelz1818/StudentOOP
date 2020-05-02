#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.h"

using namespace std;

bool operator== (const Complex& c1, const Complex& c2) {
    return ((c1.get_real() == c2.get_real()) && (c1.get_imag() == c2.get_imag()));
}

bool operator!= (const Complex& c1, const Complex& c2) {
    return !(c1 == c2);
}

Complex operator+(const Complex& c1, const Complex& c2) {
    Complex result(c1.get_real() + c2.get_real(), c1.get_imag() + c2.get_imag());
    return result;
}

Complex operator-(const Complex& c1, const Complex& c2) {
    Complex result(c1.get_real() - c2.get_real(), c1.get_imag() - c2.get_imag());
    return result;
}

ostream& operator<< (ostream& os, const Complex& c) {
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
    os << setprecision(10) << c.real << showpos
    << c.imag << "i" << noshowpos << endl;
    return os;
}


/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
    double d1, d2;
    is >> d1 >> d2;
    //is >> c.real >> c.imag;
    c.real = d1;
    c.imag = d2; 
    return is;
}


Complex::Complex(double real, double imag) : real(real), imag(imag) {}


Complex::operator bool() const {
    return ((real != 0) || (imag != 0));
}

Complex& Complex::operator++() { //pre
    ++real;
    return (*this);
}

Complex Complex::operator++(int dummy) { //post
    Complex temp(*this);
    real++;
    return temp;
}

Complex& Complex::operator--() { //pre
    --real;
    return (*this);
}

Complex Complex::operator--(int dummy) { //post
    Complex temp(*this);
    real--;
    return temp;
}

double Complex::get_real() const {
    return real;
}

double Complex::get_imag() const {
    return imag;
}

Complex& Complex::operator-=(const Complex& c){
    real -= c.get_real();
    imag -= c.get_imag();
    return *this;
}

//Complex Complex::operator*(const int i){
//    Complex result(i * real, i * imag);
//    return result;
//}

Complex Complex::operator*(const int i){
    Complex result(*this);
    result.real *= i;
    result.imag *= i; 
    return result;
}
