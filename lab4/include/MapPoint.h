#ifndef MAPPOINT_H
#define MAPPOINT_H
#include <string>


struct MapPoint{
    const char* name;
    double dlugosc;
    double szerokosc;
};


MapPoint* construct(const char* name, const double longitude, const double latitude);
void print(const MapPoint* name);
void movePoint(MapPoint* name, const double longshift, const double latshift);
MapPoint closestFrom(MapPoint* city1,MapPoint* city2, MapPoint* city3);
MapPoint inTheMiddle(MapPoint* city1, MapPoint* city2, std::string name);
void clear(MapPoint* city1,MapPoint* city2, MapPoint* city3);
void clear(MapPoint* city);
#endif