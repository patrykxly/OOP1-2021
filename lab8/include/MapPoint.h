#ifndef MAPPOINT_H
#define MAPPOINT_H
#include <string>

class MapDist;

class MapPoint{
    public:
        friend class MapDist; //zaprzyjaznianie klasy z klasa MapDist
        MapPoint(std::string city, const double dlugosc, char kier, const double szerokosc, char kier2); //pierwszy konstruktor
        MapPoint(std::string city, const double dlugosc, const double szerokosc); //drugi konstruktor
        MapPoint(); //konstruktor bezparametrowy
        ~MapPoint(); //destruktor
        void movePoint(const double zmianadl, const double zmianasz); //przesuwanie punktu o wartosci podanie w argumentach
        const MapPoint& closestPlace(const MapPoint* class1,const MapPoint* class2,const MapPoint* ref = NULL); //wyszukiwanie miejsca najblizszego do punktu referencyjnego
        friend MapPoint inTheMiddle(const MapPoint* class1,const MapPoint* class2, std::string panstwo); //funkcja zaprzyjazniona, tworzy nowy obiekt o nazwie panstwo i wyliczonych wspolrzednych posrodku dwoch obiektow
        void print() const; //wypisywanie nazwy oraz wspolrzednych obiektu
        std::string getName() const; //wypisywanie nazwy obiektu
    private:
        std::string name; //nazwa obiektu
        double longitude; //dlugosc geograficzna
        double latitude; //szerokosc geograficzna
    
};



#endif