#pragma once
#include <vector>
#include <functional>

class FunctionVector{
    private:
        std::vector<std::function<double(const double)>> _vec; ///< wektor przechowujacy obiekty funkcyjne
        std::vector<double> _resvec; ///< wektor przechowujacy wyniki kolejnych wywolan funkcji z _vec
    
    public:
        double eval(const double val); ///< metoda obliczajaca rekursywnie wyniki kolejnych wywolan funkcji

        double operator[](const double val) const; ///< operator[] dla FunctionVector
        FunctionVector& operator+=(std::function<double(double)> func);  ///< operator += dodajacy kolejne obiekty funkcyjne do wektora _vec

        void clear(); ///< czyszczenie _vec oraz _resvec
};