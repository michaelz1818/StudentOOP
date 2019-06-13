#ifndef vector_hpp
#define vector_hpp


const int DEF_CAPACITY = 10;

class Vector {
public:
    Vector();
    
    // copy control:
    Vector(const Vector& v2);
    ~Vector();
    Vector& operator=(const Vector& v2);
    
    void push_back(int val);
    int size() const { return sz; }
    int operator[](int i) const;
    int& operator[](int i);
private:
    int* data;
    int sz;
    int capacity;
};


void print_vector(Vector v);

#endif /* vector_hpp */
