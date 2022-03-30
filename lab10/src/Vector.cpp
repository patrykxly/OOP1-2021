#include "Vector.h"
#include <cmath>

double& Vector::vec(int index){
    return *(_array+index);
}

int Vector::getRozmiar() const{
   return this->_rozmiar;
}

double* Vector::getArr() const{
    return this->_array;
}

Vector sum(const Vector& V1, const Vector& V2){
    int size1 = V1.getRozmiar();
    int size2 = V2.getRozmiar();
    double *tab1 = V1.getArr();
    double *tab2 = V2.getArr();
    if(size1 > size2) {
        double *to_return = new double[size1];
        for(int i=0;i<size2;i++) to_return[i] = tab1[i] + tab2[i];
        for(int i=size2;i<size1;i++) to_return[i] = tab1[i];
        return Vector(size1, to_return);
    }
    else {
        double *to_return = new double[size2];
        for(int i=0;i<size1;i++) to_return[i] = tab1[i] + tab2[i];
        for(int i=size1;i<size2;i++) to_return[i] = tab2[i];
        return Vector(size2, to_return);
    }
}


double dot(const Vector& v1, const Vector& v2){
    double result = 0.0;
    int size1 = v1.getRozmiar(), size2 = v2.getRozmiar();
    double *tab1 = v1.getArr();
    double *tab2 = v2.getArr();
    for(int i = 0; i < v1.getRozmiar();i++){
        result += tab1[i]*tab2[i];
    }
    return result;
}

double Vector::norm() const{
    return sqrt(dot(*this,*this));
}

Vector::operator double() const{
    return norm();
}

void Vector::print(std::string string) const{
    std::cout << string << "[";
    for(int i = 0; i < _rozmiar-1; i++)
        std::cout << _array[i] << ", ";
    std::cout << _array[_rozmiar-1] << "]" << std::endl;
}