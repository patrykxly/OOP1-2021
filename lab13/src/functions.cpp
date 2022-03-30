#include "functions.h"

double Linear::operator()(const double x){
    return _a*x + _b;
}

double Pow::operator()(const double x) const{
    return pow(x,_val);
}

double Cos::operator()(const double num){
    return cos(_a*num + _b);
}

double Abs::operator()(const double num) const{
    if(num < 0)
        return -num;
    return num;
}


std::ostream& operator<<(std::ostream& os, const Linear& lin){
    os << lin._a << "*x";
    if(lin._b > 0)
        os << "+" << lin._b;
    else
        os << "-" << -lin._b;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Pow& pow){
    os << "x^" << pow._val;
    return os;
}