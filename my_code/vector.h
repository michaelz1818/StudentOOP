#ifndef vector_hpp
#define vector_hpp



const int DEF_CAPACITY = 10;

class MyVec {
public:
    class Iterator {
        /*
         * This class supports ranged for loops.
         * It includes:
         * Iterator(int*)
         * operator++
         * operator*
         * operator!=
         * */
        friend bool operator!=(const Iterator& lhs, const Iterator& rhs){return lhs.ipr != rhs.ipr;}
        int* ipr;
        
    public:
        Iterator(int* p) : ipr(p) {}
        Iterator& operator++();
        int operator*() {return *ipr;}
    };
    
    MyVec();
    MyVec(int, int val = 0);
    
    // copy control:
    MyVec(const MyVec& v2);
    ~MyVec();
    MyVec& operator=(const MyVec& v2);
    
    void push_back(int val);
    int size() const { return sz; }
    int operator[](int i) const;
    int& operator[](int i);
    Iterator begin() const;
    Iterator end() const;
    
private:
    int* data;
    int sz;
    int capacity;
};


void print_vector(const MyVec& v);

bool operator==(MyVec& v1, MyVec& v2); 

#endif /* vector_hpp */
