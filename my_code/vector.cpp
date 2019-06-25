#include <iostream>
#include "vector.h"

using namespace std;

void print_vector(const MyVec& v) {
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
}

MyVec::Iterator::Iterator(int* p) {ipr = p;}

MyVec::Iterator& MyVec::Iterator::operator++(){
    ++ipr;
    return *this;
}

int MyVec::Iterator::operator*() {return *ipr;}

MyVec::MyVec() : sz(0), capacity(DEF_CAPACITY), data(new int[DEF_CAPACITY]) {}

MyVec::MyVec(int size, int val) : sz(size), capacity(size*2) {
    data = new int[capacity]; 
    for(int i = 0; i < size; ++i){
        data[i] = val;
    }
}

MyVec::MyVec(const MyVec& v2) {
    sz = v2.sz;
    capacity = v2.capacity;
    data = new int[capacity];
    for(int i = 0; i < capacity; ++i){
        data[i] = v2.data[i]; 
    }
}

MyVec::~MyVec() {
    if(data != nullptr) delete [] data;
}

MyVec& MyVec::operator=(const MyVec& v2) {
    if(this != &v2){
        if(data != nullptr) delete [] data;
        sz = v2.sz;
        capacity = v2.capacity;
        data = new int[capacity];
        for(int i = 0; i < capacity; ++i){
            data[i] = v2.data[i];
        }
    }
    return *this;
}


/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
bool operator==(MyVec& v1, MyVec& v2) {
    if(v1.size() != v2.size()) return false;
    else {
        for(int i = 0; i < v1.size(); ++i){
            if(v1[i] != v2[i]) return false;
        }
    }
    return true;
}

//bool operator==(MyVec& v1, MyVec& v2) {
//    if(v1.size() == v2.size()){
//        int i = 0;
//        while (i < v1.size() && i >= 0) {
//            if(v1[i] == v2[i]) ++i;
//            else i = -1;
//        }
//        if(i != -1) return  true;
//    }
//    return false;
//}

/*
 * Puts an element at the back of a vector.
 * */
void MyVec::push_back(int val) {
    if(sz == capacity){
        capacity *= 2;
        int* temp = new int[capacity];
        for(int i = 0; i < sz; ++i) temp[i] = data[i];
        delete [] data;
        data = temp;
    }
    data[sz++] = val;
}

/*
 * this [] is for reading items from the MyVec:
 * It returns the i-th element.
 * */
int MyVec::operator[](int i) const {
    return data[i];
}

/*
 * this [] allows write access to items in the MyVec:
 * It returns a reference to the i-th element.
 * */
int& MyVec::operator[](int i) {
    return data[i];
}

MyVec::Iterator MyVec::begin() const{
    return MyVec::Iterator(data);
}

MyVec::Iterator MyVec::end() const{
    return MyVec::Iterator(data + sz);
}
