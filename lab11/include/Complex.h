#ifndef COMPLEX_H
#define COMPLEX_H
#include "Vector.h"
#include <iostream>
#include <utility>


namespace complex{
    class Complex{
        private:
            double _re;
            double _im;
        public:
            Complex(const double val1 = 0, const double val2 = 0) : _re(val1),_im(val2){};
            Complex(const vector::Vector &Vec);
            Complex(const Complex& comp) : _re(comp._re), _im(comp._im){};
            Complex(Complex&& comp) : _re(comp._re), _im(comp._im){comp._re = 0.0;comp._im = 0.0;}
            ~Complex(){_re = 0.0; _im = 0.0;}
            operator double() const;
            operator vector::Vector() const;
            void print(std::string napis);
            double getRe();
            double getIm();            
    };
    Complex sum(Complex& z1, Complex& z2);
    Complex sum(const double l1, const double l2);
}

#endif