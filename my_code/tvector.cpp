#include <iostream>
#include "tvector.h"

using namespace std;

//template <typename T>
//void print_vector(const MyVec<T>& v) {
//    for(int i = 0; i < v.size(); ++i){
//        cout << v[i] << " ";
//    }
//}

//template <typename T>
//MyVec<T>::MyVec() : sz(0), capacity(DEF_CAPACITY), data(new T[DEF_CAPACITY]) {}

//template <typename T>
//MyVec<T>::MyVec(int size, T val) : sz(size), capacity(size*2) {
//    data = new T[capacity];
//    for(int i = 0; i < size; ++i){
//        data[i] = val;
//    }
//}

//template <typename T>
//MyVec<T>::MyVec(const MyVec<T>& v2) {
//    sz = v2.sz;
//    capacity = v2.capacity;
//    data = new T[capacity];
//    for(int i = 0; i < capacity; ++i){
//        data[i] = v2.data[i]; 
//    }
//}

//template <typename T>
//MyVec<T>::~MyVec() {if(data != nullptr) delete [] data;}

//template <typename T>
//MyVec<T>& MyVec<T>::operator=(const MyVec<T>& v2) {
//    if(this != &v2){
//        if(data != nullptr) delete [] data;
//        sz = v2.sz;
//        capacity = v2.capacity;
//        data = new int[capacity];
//        for(int i = 0; i < capacity; ++i){
//            data[i] = v2.data[i];
//        }
//    }
//    return *this;
//}


/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
//template<typename T>
//bool operator==(MyVec<T>& v1, MyVec<T>& v2) {
//    if(v1.size() != v2.size()) return false;
//    else {
//        for(int i = 0; i < v1.size(); ++i){
//            if(v1[i] != v2[i]) return false;
//        }
//    }
//    return true;
//}

/*
 * Puts an element at the back of a vector.
 * */
//template <typename T>
//void MyVec<T>::push_back(T val) {
//    if(sz == capacity){
//        capacity *= 2;
//        T* temp = new T[capacity];
//        for(int i = 0; i < sz; ++i) temp[i] = data[i];
//        delete [] data;
//        data = temp;
//    }
//    data[sz++] = val;
//}

///*
// * this [] is for reading items from the MyVec:
// * It returns the i-th element.
// * */
//template <typename T>
//T MyVec<T>::operator[](unsigned int i) const {
//    return data[i];
//}
//
///*
// * this [] allows write access to items in the MyVec:
// * It returns a reference to the i-th element.
// * */
//template <typename T>
//T& MyVec<T>::operator[](unsigned int i) {
//    return data[i];
//}
