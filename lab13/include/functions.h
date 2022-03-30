#pragma once
#include <cmath>
#include <iostream>

class Linear{
    private:
        double _a;
        double _b;
    
    public:
        ///< konstruktory
        Linear(double x, double y) : _a{x},_b{y}{};

        double operator()(const double x); ///< operator() dla Linear
        
        friend std::ostream& operator<<(std::ostream& os, const Linear& lin); ///< operator ostream dla Linear
};


class Pow{
    private:
        int _val;
    
    public:
        Pow() : _val{2}{}; ///< konstruktor, ktory domyslnie przypisuje druga potege dla liczby
        Pow(int num) : _val{num}{}; ///< konstruktor przypisujacy potege o wartosci num dla liczy
        
        double operator()(const double x) const; ///< operator() dla Pow

        friend std::ostream& operator<<(std::ostream& os, const Pow& pow); ///< operator ostream dla Pow
};


class Cos{
    private:
        double _a;
        double _b;
    
    public:
        Cos(double x, double y) : _a{x},_b{y}{}; ///< konstruktor

        double operator()(const double num); ///< operator() dla Cos
};


class Abs{
    public:
        double operator()(const double num) const; ///< operator() dla Abs
};