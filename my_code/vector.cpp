#include <iostream>
#include "vector.h"

using namespace std;

void print_vector(Vector v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


Vector::Vector() {
    sz = 0;
    capacity = DEF_CAPACITY;
    data = new int[DEF_CAPACITY];
}

Vector::Vector(const Vector& v2) {
    capacity = v2.capacity;
    sz = v2.size();
    data = new int[capacity];
    // copy over existing data
    for (int i = 0; i < size(); i++) {
        data[i] = v2.data[i];
    }
}

Vector::~Vector() {
    delete[] data;
}

Vector& Vector::operator=(const Vector& v2) {
    if (&v2 != this) {
        delete[] data;
        capacity = v2.capacity;
        sz = v2.size();
        data = new int[capacity];
        // copy over existing data
        for (int i = 0; i < size(); i++) {
            data[i] = v2.data[i];
        }
    }
    return *this;
}


void Vector::push_back(int val) {
    if (sz == capacity) {
        cout << "Increasing capacity\n";
        // get new array of capacity * 2
        capacity *= 2;
        int* new_data = new int[capacity];
        // copy over existing data
        for (int i = 0; i < size(); i++) {
            new_data[i] = data[i];
        }
        // delete old array
        delete[] data;
        // set pointer to new array
        data = new_data;
    }
    data[sz++] = val;
}

int Vector::operator[](int i) const {
    return data[i];
}

int& Vector::operator[](int i) {
    return data[i];
}
