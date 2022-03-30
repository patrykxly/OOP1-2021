#pragma once
#include <cstdio>
#include <iostream>

class Fraction{
    private:
        int _l;
        int _m;

    public:
        ///< upraszczanie ulamka
        void simplify();

        ///< Konstruktory
        Fraction(int x, int y = 1) : _l(x), _m(y){simplify();};
        Fraction(const Fraction& obj) : Fraction(obj._l,obj._m){};

        ///< operatory
        explicit operator double() const;
        Fraction operator+(const Fraction& obj) const;
        Fraction operator*(const Fraction& obj) const;
        Fraction& operator+=(int val);
        Fraction& operator*=(int val);
        const Fraction& operator=(const Fraction& obj);
        Fraction operator-() const;

        /// <gettery i settery
        int getL(){return _l;};
        int getM(){return _m;}


        void setL(int val){_l = val;};
        void setM(int val){_m = val;};

        ///< do outputu
        friend std::ostream& operator<<(std::ostream& os, const Fraction& fr);
};

///< operatory na zewnatrz klasy
Fraction operator*(int val, Fraction fr);
Fraction operator+(int val, Fraction fr);
Fraction operator+(Fraction fr, int val);
bool operator==(Fraction fr1, Fraction fr2);