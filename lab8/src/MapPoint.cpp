#include "MapPoint.h"
#include "MapDist.h"
#include <cmath>
#include <iostream>

MapPoint::MapPoint(std::string city, const double dlugosc, char kier, const double szerokosc, char kier2){
    name = city;
    if(kier == 'W')
        longitude = -dlugosc;
    else
        longitude = dlugosc;
    if(kier2 == 'S')
        latitude = -szerokosc;
    else
        latitude = szerokosc;
}

MapPoint::MapPoint(std::string city, const double dlugosc,const double szerokosc){
    name = city;
    longitude = dlugosc;
    latitude = szerokosc;
}

MapPoint::MapPoint(){
    name = "Punkt";
    longitude = 0.0;
    latitude = 0.0;
}

MapPoint::~MapPoint(){
    std::cout << "Usuwanie " << name << std::endl;
}

void MapPoint::movePoint(const double zmianadl, const double zmianasz){
    longitude += zmianadl;
    latitude += zmianasz;
}

const MapPoint& MapPoint::closestPlace(const MapPoint* class1,const MapPoint* class2,const MapPoint* ref){
    if(ref == NULL)
        ref = this;
    MapDist dist1(*class1,*ref), dist2(*class2,*ref);
    if(dist1.angularDistance() > dist2.angularDistance())
        return *class2;
    return *class1;
}

MapPoint inTheMiddle(const MapPoint* class1,const MapPoint* class2, std::string panstwo){
    MapPoint result(panstwo,(class1->longitude+class2->longitude)/2,(class1->latitude+class2->latitude)/2);
    return result;
}

void MapPoint::print() const{
    std::cout << "Wspolrzedne dla " << name << ": " << fabs(longitude);
    if(longitude < 0.0)
        std::cout << "W, " << fabs(latitude);
    else
        std::cout << "E, " << fabs(latitude);
    if(latitude < 0.0)
        std::cout << "S" << std::endl;
    else
        std::cout << "N" <<std::endl;
}

std::string MapPoint::getName() const{
    return name;
}



