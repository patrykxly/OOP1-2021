#include "Vector2D.h"
#include <iostream>
#include <cmath>

int Vector2D::count = 0;

Vector2D::~Vector2D(){
    this->_x=0.0;
    this->_y=0.0;
    this->_name = "";
    //count--; // w celu zmniejszenia liczby wektorow
}

Vector2D::Vector2D(std::string name,const double x,const double y){
    _name = name;
    _x = x;
    _y = y;
    Vector2D::count++; 
    _NumOfObj = count;
}

Vector2D::Vector2D(std::string name){
    Vector2D::count++; 
    _NumOfObj = count;
    _name = name;
    _x = 0;
    _y = 0;
}

Vector2D::Vector2D(const Vector2D& wektor){
    _NumOfObj = wektor._NumOfObj;
    _x = wektor._x;
    _y = wektor._y;
    _name = std::move(wektor._name);
    Vector2D::count++;
    std::cout << "--- kopiowanie ";
    print();
    _NumOfObj = count;
}

Vector2D::Vector2D(Vector2D&& wektor){
    _NumOfObj = wektor._NumOfObj;
    _x = wektor._x;
    _y = wektor._y;
    _name = std::move(wektor._name);
    std::cout << "--- przenoszenie ";
    print();
    wektor._x = 0.0;
    wektor._y = 0.0;
    _NumOfObj = count;
}

Vector2D Vector2D::fromCarthesian(std::string name, const double x,const double y){
    return Vector2D(name,x,y);
}

Vector2D Vector2D::fromCarthesian(const double x,const double y){
    return Vector2D("Vx",x,y);
}

Vector2D Vector2D::fromPolar(std::string name,const double promien,const double kat){
    double change = kat*M_PI/180.;
    double x = promien*cos(change);
    double y = promien*sin(change);
    return Vector2D(name,x,y);
}

Vector2D Vector2D::fromPolar(const double promien,const double kat){
    double change = kat*2.*M_PI/360.;
    double x = promien*cos(change);
    double y = promien*sin(change);
    return Vector2D("Vx",x,y);
}


double Vector2D::dot(const Vector2D& wektor) const{
    return(_x*wektor._x+_y*wektor._y);
}

void Vector2D::print() const{
    std::cout << "Obiekt " << this->_NumOfObj << ": " << this->_name << "=(" << _x << "," << _y << ")" << std::endl;
}

Vector2D Vector2D::add(const Vector2D& wektor) const{
    return Vector2D::fromCarthesian(_x+wektor._x,_y+wektor._y);
}