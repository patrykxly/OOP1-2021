#ifndef VECTOR_H
#define VECTOR_H
#include <utility>
#include <iostream>

namespace vector{
    class Vector{
        private:
            int _rozmiar;  
            double* _array;
        public:
            explicit Vector(const int roz) : _rozmiar(roz), _array(new double[_rozmiar*sizeof(double)]){for(int i = 0; i < _rozmiar; i++){_array[i] = 0.0;}}
            explicit Vector(const double val) : _rozmiar(1), _array(new double[_rozmiar*sizeof(double)]){ *_array = val; }
            Vector(const double val1, const double val2) : _rozmiar(2), _array(new double[_rozmiar*sizeof(double)]){_array[0] = val1; _array[1] = val2;}
            Vector(const int roz,double* arr) : _rozmiar(roz),_array(arr){};
            Vector(const Vector& vec) : _rozmiar(vec._rozmiar), _array(new double[_rozmiar*sizeof(double)]) {for(int i = 0; i < _rozmiar; i++){_array[i]=vec._array[i];}}
            Vector(Vector&& vec) : _rozmiar(vec._rozmiar), _array(std::move(vec._array)){vec._rozmiar = 0;}
            ~Vector(){if(_rozmiar > 0) {delete [] _array;}} //destruktor

            int getRozmiar() const; //getter dla rozmiaru obiektu
            double* getArr() const; 

            Vector extended(int newsize) const;
            double& vec(int index); //metoda zwracajaca adres do konkretnego indexu wektora;
            double norm() const; //znormalizowanie wektora
            operator double() const; //operator przeksztalcajacy na double
            void print(std::string string) const; //drukowanie wektora
        
            double &operator[](int i) const { return _v[i]; };

    };

    Vector sum(const Vector& v1, const Vector& v2); //suma dwoch wektorow 
    double dot(const Vector& v1, const Vector& v2); //iloczyn dwoch wektorow
}

#endif