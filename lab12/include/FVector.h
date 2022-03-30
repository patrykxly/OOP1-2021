#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "Fraction.h"

class FVector{
    private:
        std::vector<Fraction> _wektor;

    public:
        FVector(Fraction fr); ///<konstruktor
        
        FVector& operator+=(Fraction fr); ///<operator +=
        friend std::ostream& operator<<(std::ostream& os, const FVector& wekt); ///<wypisywanie wektora

        void sort(); ///<sortowanie wektora
};

FVector::FVector(Fraction fr){
    _wektor.push_back(fr);
}

FVector& FVector::operator+=(Fraction fr){
    if(fr.getM() < 0){
        fr.setM(fr.getM()-fr.getM()*2);
        fr.setL(-fr.getL());
    }
    _wektor.push_back(fr);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const FVector& wekt){
    os << "[";
    for(int i =0; i < static_cast<int>(wekt._wektor.size())-1; i++)
        os << wekt._wektor[i] << ", ";
    os << wekt._wektor[wekt._wektor.size()-1] << "]" << std::endl;
    return os;
}

///< funkcja sortujaca do sort
bool sortingfunction(Fraction& fr1,Fraction& fr2){
    return static_cast<double>(fr1) < static_cast<double>(fr2);
}

void FVector::sort(){
    std::sort(_wektor.begin(),_wektor.end(), sortingfunction);
}