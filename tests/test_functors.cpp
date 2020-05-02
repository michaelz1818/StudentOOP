//
//#include <iostream>
//#include <functional>
//#include <cmath>
//
//using namespace std;
//
//const double PI = 3.14159265358979323846;
//
//class NoNegative : public exception {
//public:
//    NoNegative(int n) : badnum(n) {}
//
//    const char* what() const throw() {
//        string s = "Argument cannot be negative: " + to_string(badnum);
//        return s.c_str();
//    }
//
//private:
//    int badnum;
//};
//
//class Sin {
//public:
//    double operator()(double r) {
//        return sin(r);
//    }
//};
//
//class Fib {
//public:
//    Fib() {
//        for(int i = 0; i < MAX_FIB; ++i){
//            fibs[i] = NOT_CALCED;
//        }
//    }
//
//    long long int operator()(int n) {
//        if(n < 0 || n > MAX_FIB) throw NoNegative(n);
//        if(fibs[n] == NOT_CALCED){
//            if (n <= 1) fibs[n] = 1;
//            else fibs[n] = operator()(n - 1) + operator()(n - 2);
//        }
//        return fibs[n];
//    }
//
//    const int MAX_FIB = 100;
//    const int NOT_CALCED = -1;
//private:
//    long long int* fibs = new long long int[MAX_FIB];
//};
//
//
//double your_func(double d, function<double(double)> f) {
//    double result = 0;
//    while(result < 69 && result > -69 && f(d) != 0){
//        result += (f(d) * exp(f(d)));
//    }
//    return floor(abs(result));
//}
//
//
//double your_func2(double d, function<double(double)> f) {
//    return cbrt(f(d));
//}
//
//
//double your_func3(double d, function<double(double)> f) {
//    return sqrt(f(d));
//}
//
//double square_func(double d, function<double(double)> f) {
//    return f(d) * f(d);
//}
//
//
//int main() {
//    const long long int FIB_NUM = 14;
//
//    // first functors:
//    Sin sine = Sin();
//    double d = sine(PI / 2);
//    cout << "sin pi / 2 == " << d << endl;
//    d = sine(0);
//    cout << "sin 0 == " << d << endl;
//    Fib fib = Fib();
//    try {
//        long long int f = fib(FIB_NUM);
//        cout << "fib(" << FIB_NUM << ") == " << f << endl;
//    }
//    catch (NoNegative& e) {
//        cerr << "Got a negative argument for fib: " << e.what() << endl;
//    }
//
//    // then lambdas -- use several functions from cmath here:
//    d = square_func(0, [](double arg) { return sin(arg); });
//    cout << "Square of sin 0 = " << d << endl;
//    d = square_func(1, [](double arg) { return sin(arg); });
//    cout << "Square of sin 1 = " << d << endl;
//
//     // you're call here!
//    d = your_func2(1, [](double arg) {return cos(arg);});
//     cout << "my_func2 of cos 1 = " << d << endl;
//     // you're call here!
//    d = your_func3(0, [](double arg) {return tan(arg);});
//     cout << "my_func3 of tan 0 = " << d << endl;
//     // you're call here!
//    d = your_func(1, [](double arg) {return cos(arg);});
//    cout << "my_func1 of cos 1 = " << d << endl;
//    d = your_func3(1, [](double arg) {return cos(arg);});
//    cout << "my_func3 of cos 1 = " << d << endl;
//
//}
