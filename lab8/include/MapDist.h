#ifndef MAPDIST_H
#define MAPDIST_H
#include "MapPoint.h"

class MapPoint;

class MapDist{
    public:
        friend class MapPoint; //zaprzyjaznianie klasy z klasa MapPoint
        friend MapDist distance(const MapPoint& city1,const MapPoint& city2); //wyliczanie dystansu miedzy 2 punktami wzgledem dlugosci, szerokosci geograficznej oraz ogolny dystans
        MapDist(const MapPoint& city1,const MapPoint& city2); //konstruktor
        double angularDistance() const; //wypisuje ogolny dystans miedzy 2 punktami
        double getlongitude() const; //wypisuje dystans miedzy 2 punktami wzgledem dlugosci geograficznej
        double getlatitude() const; //wypisuje dystans miedzy 2 punktami wzgledem szerokosci geograficznej
    private:
        double longitudediff; //roznica dystansu miedzy 2 pkt wzgledem dlugosci geograficznej
        double latitudediff; //roznica dystansu miedzy 2 pkt wzgledem szerokosci geograficznej
        double diff; //ogolna roznica dystansu miedzy 2 pkt
};

MapDist distance(const MapPoint& city1,const MapPoint& city2); //wyliczanie dystansu miedzy 2 punktami wzgledem dlugosci, szerokosci geograficznej oraz ogolny dystans
#endif