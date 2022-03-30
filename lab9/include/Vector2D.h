#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <string>

class Vector2D{
    private: 
        double _x; //wspolrzedna x
        double _y; //wspolrzedna y
        int _NumOfObj; //numer aktualnego wektora
        std::string _name; //"nazwa" wektora
        Vector2D(std::string name,const double x,const double y); //prywatny konstruktor klasy
    public:
        Vector2D(std::string name); //konstruktor dla argumentu typu string
        ~Vector2D(); //destruktor
        static int count; //liczba utworzonych wektorow
        Vector2D(const Vector2D& wektor); //konstruktor kopiujacy
        Vector2D(Vector2D&& wektor); //konstruktor przenoszaccy
        static Vector2D fromCarthesian(std::string name, const double x,const double y); //funkcja statyczna nadajaca parametry wektorowi
        static Vector2D fromCarthesian(const double x,const double y); //j.w, domyslnie name = "Vx"
        static Vector2D fromPolar(std::string name, const double promien,const double kat); //funkcja statyczna zmieniajaca uklad biegunowy na kartezjanski i nadajaca parametry wektorowi
        static Vector2D fromPolar(const double promien, const double kat); //j.w, domyslnie name = "Vx" 
        void print() const; //wypisywanie wektora
        double dot(const Vector2D& wektor) const; //wyliczanie iloczynu skalarnego wektorow
        Vector2D add(const Vector2D& wektor) const; //sumowanie wektorow
};

#endif