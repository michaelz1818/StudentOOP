#ifndef tvector_h
#define tvector_h

const int DEF_CAPACITY = 20;

template <typename T>
class MyVec {
public:
    MyVec() : sz(0), capacity(DEF_CAPACITY) {data(new T[DEF_CAPACITY]);}
    
    MyVec(int size, T val) : sz(size), capacity(size*2) {
        data = new T[capacity];
        for(int i = 0; i < size; ++i){
            data[i] = val;
        }
    }
    
    // copy control:
    MyVec(const MyVec<T>& v2) {
        sz = v2.sz;
        capacity = v2.capacity;
        data = new T[capacity];
        for(int i = 0; i < capacity; ++i){
            data[i] = v2.data[i];
        }
    }
    
    ~MyVec() {if(data != nullptr) delete [] data;}
    
    MyVec<T>& operator=(const MyVec<T>& v2) {
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
    
    void push_back(T val) {
        if(sz == capacity){
            capacity *= 2;
            T* temp = new T[capacity];
            for(int i = 0; i < sz; ++i) temp[i] = data[i];
            delete [] data;
            data = temp;
        }
        data[sz++] = val;
    }
    
    int size() const { return sz; }
    
    T operator[](unsigned int i) const {return data[i];}
    
    T& operator[](unsigned int i) {return data[i];}
    
private:
    T* data;
    int sz;
    int capacity;
};

template<typename T>
bool operator==(MyVec<T>& v1, MyVec<T>& v2) {
    if(v1.size() != v2.size()) return false;
    else {
        for(int i = 0; i < v1.size(); ++i){
            if(v1[i] != v2[i]) return false;
        }
    }
    return true;
}

template <typename T>
void print_vector(const MyVec<T>& v) {
    for(int i = 0; i < v.size(); ++i){
        std::cout << v[i] << " ";
    }
}

#endif /* tvector_h */
