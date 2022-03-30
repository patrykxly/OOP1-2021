#include "MapDist.h"
#include <cmath>

MapDist::MapDist(const MapPoint& city1,const MapPoint& city2){
    longitudediff = fabs(city1.longitude - city2.longitude);
    latitudediff = fabs(city1.latitude-city2.latitude);
    diff = sqrt(longitudediff*longitudediff + latitudediff*latitudediff);
}

MapDist distance(const MapPoint& city1,const MapPoint& city2){
    MapDist result(city1,city2);
    return result;
}

double MapDist::angularDistance() const{
    return diff;
}

double MapDist::getlongitude() const{
    return longitudediff;
}

double MapDist::getlatitude() const{
    return latitudediff;
}
