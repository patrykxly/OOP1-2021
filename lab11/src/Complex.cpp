    #include "Complex.h"

using complex::Complex;

Complex::Complex(const vector::Vector &Vec){
    double* arr = Vec.getArr();
    _re = arr[0];
    _im = arr[1];
}

double Complex::getRe(){
    return this->_re;
}

double Complex::getIm(){
    return this->_im;
}

void Complex::print(std::string napis){
    std::cout << napis << this->_re << " + " << this->_im << "i" << std::endl;
}

Complex complex::sum(Complex& z1, Complex& z2){
    return Complex(z1.getRe()+z2.getRe(),z1.getIm()+z2.getIm());
}


Complex::operator double() const{
    return static_cast<double>(_re);
}

Complex::operator vector::Vector() const{
    return vector::Vector(this->_re,this->_im);
}
