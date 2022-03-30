#include <cstdio>
#include <iostream>
#include "MapPoint.h"
#include <cmath>

MapPoint* construct(const char* name, double longitude, double latitude){
    MapPoint* Created =  (MapPoint*)malloc(sizeof(MapPoint)); //alokowanie przestrzeni dla Created
    Created->name = name;
    Created->dlugosc = longitude;
    Created->szerokosc = latitude;
    return Created;
}

void print(const MapPoint* name){
    std::cout << "Wspolrzedne dla " << name->name << ": ";
    if(name->dlugosc > 0)
        std::cout << name->dlugosc << "E, ";
    else
        std::cout << name->dlugosc-name->dlugosc-name->dlugosc << "W, ";
    if(name->szerokosc > 0)
        std::cout << name->szerokosc << "N" << std::endl;
    else
        std::cout << name->szerokosc-name->szerokosc-name->szerokosc << "S" << std::endl; //aby w outpucie nie bylo - 
}

void movePoint(MapPoint* name, const double longshift, const double latshift){
    name->dlugosc = name->dlugosc + longshift;
    name->szerokosc = name->szerokosc + latshift;
}

MapPoint closestFrom(MapPoint* city1,MapPoint* city2, MapPoint* city3){
    double angularDistance1 = sqrt((city1->dlugosc - city2->dlugosc)*(city1->dlugosc - city2->dlugosc) + (city1->szerokosc - city2->szerokosc)*(city1->szerokosc - city2->szerokosc)); //obliczanie dystansu od 2 miasta
    double angularDistance2 = sqrt((city1->dlugosc - city3->dlugosc)*(city1->dlugosc - city3->dlugosc) + (city1->szerokosc - city3->szerokosc)*(city1->szerokosc - city3->szerokosc)); //obliczanie dystansu od 3 miasta
    MapPoint result;
    if(angularDistance1 < angularDistance2){ //zwracamy mniejszy dystans
        result.name = city2->name;
    }
    else
        result.name = city3->name;
    return result;
}

MapPoint inTheMiddle(MapPoint* city1, MapPoint* city2, const char* name){
    MapPoint result;
    result.name = name;
    result.dlugosc = (city1->dlugosc + city2->dlugosc)/2;
    result.szerokosc = (city1->szerokosc + city2->szerokosc)/2;
    return result;
}

void clear(MapPoint* city1,MapPoint* city2, MapPoint* city3){
    std::cout << "Usuwanie " << city1->name << std::endl;
    free(city1);
    std::cout << "Usuwanie " << city2->name << std::endl;
    free(city2);
    std::cout << "Usuwanie " << city3->name << std::endl;
    free(city3);
    
}

void clear(MapPoint* city){
    std::cout << "Usuwanie " << city->name << std::endl;
    free(city);
}


