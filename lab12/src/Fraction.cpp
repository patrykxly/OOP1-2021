#include "Fraction.h"
#include <algorithm>


int nwd(int m, int n){
        int oldm, oldn;
    if(n!=0){
        while( m % n != 0 ){
            oldm = m;
            oldn = n;
                m = oldn;
                n = oldm % oldn;
            }
        return n; 
    }
    return 0;
}


void Fraction::simplify(){
    int dzielnik = nwd(_l,_m);
    if(dzielnik != 0){
        _l = _l/dzielnik;
        _m = _m/dzielnik;
    }
}

std::ostream& operator<<(std::ostream& os, const Fraction& fr){
    int jednosci = 0;
    int licznik = fr._l;
    int mianownik = fr._m;
    if(licznik > 0 && mianownik > 0){
        while(licznik >= mianownik){
            licznik -= mianownik;
            jednosci++;  
        }
    }
    else if(licznik > 0 && mianownik < 0){
        if(mianownik-mianownik*2 <= licznik){
            mianownik = mianownik - mianownik*2;
            while(licznik >= mianownik){
                licznik -= mianownik;
                jednosci--;
            }
        }
    }
    else if(licznik < 0 && mianownik < 0){
        mianownik = mianownik - mianownik*2;
        licznik = licznik - licznik*2;
         while(licznik >= mianownik){
            licznik -= mianownik;
            jednosci++;  
        }
    }
    else{
        if(licznik - licznik*2 >= mianownik){
            licznik = licznik - licznik*2;
            while(licznik >= mianownik){
                licznik -= mianownik;
                jednosci--;  
            }
        }
    }
    if(licznik == 0)
        os << jednosci;
    else if(jednosci != 0 && licznik != 0)
        os << jednosci << " " << licznik << "/" << mianownik;
    else
        os << licznik << "/" << mianownik;
    return os;
}


Fraction Fraction::operator+(const Fraction& obj) const{
    if(_m == obj._m)
        return Fraction(_l + obj._l, _m);
    else if(_m < obj._m){
            int mianownik = _m;
            int licznik = _l;
            while(abs(mianownik) != abs(obj._m)){
                mianownik = mianownik*2;
                licznik = licznik*2;
            }
            return Fraction(licznik-obj._l,mianownik);
        }
    else{
        int mianownik = obj._m;
        int licznik = obj._l;
        while(abs(mianownik) != abs(_m)){
            mianownik = mianownik*2;
            licznik = licznik*2;
        }
        return Fraction(licznik+_l,mianownik);
    }
}

Fraction Fraction::operator*(const Fraction& obj) const{ 
    return Fraction(_l*obj._l,_m*obj._m);
}


Fraction operator *(int val, Fraction fr){
     return Fraction(fr.getL()*val,fr.getM()); 
}

Fraction& Fraction::operator+=(int val){
    _l = _l + val*_m;
    return *this;
}

const Fraction& Fraction::operator=(const Fraction& obj){
    if(&obj == this)
        return *this;
    _l = obj._l;
    _m = obj._m;
    return *this;
}

Fraction& Fraction::operator*=(int val){
    _l = _l*val;
    simplify();
    return *this;
}


Fraction::operator double() const{
    return static_cast<double>(_l)/static_cast<double>(_m);
}

Fraction Fraction::operator-() const{
    return Fraction(_l-_l*2,_m);
}

Fraction operator+(int val, Fraction fr){
    return Fraction(fr.getL() + val*fr.getM(), fr.getM());
}

Fraction operator+(Fraction fr, int val){
    return Fraction(fr.getL() + val*fr.getM(), fr.getM());
}

bool operator==(Fraction fr1, Fraction fr2){
    if(fr1.getL() == fr2.getL() && fr1.getM() == fr2.getM())
        return true;
    return false;
}