//
//  vector.hpp
//  OOPSu19
//
//  Created by Michael Zhao on 6/13/19.
//  Copyright © 2019 Michael Zhao. All rights reserved.
//

#ifndef vector_hpp
#define vector_hpp


const int DEF_CAPACITY = 10;

class vector {
public:
    vector();
    
    // copy control:
    vector(const vector& v2);
    ~vector();
    vector& operator=(const vector& v2);
    
    void push_back(int val);
    int size() const { return sz; }
    int operator[](int i) const;
    int& operator[](int i);
private:
    int* data;
    int sz;
    int capacity;
};


void print_vector(vector v);

#endif /* vector_hpp */
