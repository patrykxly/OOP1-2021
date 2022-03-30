#pragma once
#include "Operation.h"

class VSum : public Operation{ 
    public:
        VSum(const double x, const double y) : Operation{"Dodawanie",'+',x,y}{};
        VSum(double* arr, double size ) : Operation("Dodawanie",'+',arr,size){};
        double eval() const override ;
};

double VSum::eval() const{
    double res;
    for(int i = 0; i < 4; i++)
        res += _array[i];
    return res;
}