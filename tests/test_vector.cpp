#include <cassert>
#include <iostream>
#include "../my_code/vector.h"

using namespace std;

int copy_vector(Vector v) {
    Vector local_v = v;
    return local_v.size();
}

int main() {
    Vector v = Vector();
    for (int i = 0; i < 200; i++) {
        v.push_back(i);
        copy_vector(v);
    }
    for (int i = 0; i < 200; i++) {
        v[i] *= 2;
    }
    Vector v3;
    for (int i = 9; i < 99; i += 9) {
        v3.push_back(i);
    }
    
    Vector v2 = v;
    print_vector(v2);
    
    v2 = v3;
    print_vector(v3);
}
