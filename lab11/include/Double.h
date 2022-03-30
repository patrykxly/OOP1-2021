#ifndef DOUBLE_H
#define DOUBLE_H
#include "Vector.h"


class Double{
    private:
        double _val;
        int _counter;
    public:
        Double(): _val(0){};
        Double(double x) : _val(x),_counter(0){};
        Double(const Vector &v) : Double(v.norm()){};
        void print() const;
        void setconstx(double val) const{const_cast<Double *>(this)->_val = val};
        Double setx(vector::Vector vec){
            return Double();
        }
        operator vector::Vector() const{
            return Double();
        }

};

void print(Double value);

#endif