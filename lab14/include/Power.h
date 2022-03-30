#pragma once
#include "Operation.h"
#include <cmath>

class Power : public Operation{
    public:
        Power(const double x,const double y) : Operation{"Potegowanie",'^',x,y}{};
        double eval() const override{return pow(_x,_y);};
};