#include "functionVector.h"
#include <iostream>
FunctionVector& FunctionVector::operator+=(std::function<double(const double)> func){
    _vec.push_back(func);
    return *this;
}

double FunctionVector::operator[](const double val) const{
    return _resvec[val];
}


double FunctionVector::eval(const double val){
    _resvec.clear(); ///< czyscimy wektor wynikow, by przy powtorzeniu metody dla innego val nie bylo wynikow dla poprzedniej wartosci
    _resvec.push_back(_vec[0](val));
    for(int i = 1; i < static_cast<int>(_vec.size()); i++)
        _resvec.push_back(_vec[i](_resvec[i-1]));
    return _resvec[_resvec.size()-1];
}

void FunctionVector::clear(){
    _resvec.clear();
    _vec.clear();
}

