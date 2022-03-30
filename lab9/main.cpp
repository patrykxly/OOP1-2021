/* Celem zadania jest przećwiczenie konstruktorów, a także funkcji i zmiennych statycznych.

Wektor można przedstawić np. we współrzędnych biegunowych lub kartezjańskich lecz konstruktor z dwoma argumentami double byłby niejednoznaczny:
   Vector2D (double x, double y);
   Vector2D (double r, double phi); // błąd - zdublowany z poprzednim
Należy użyć tzw. named constructor idiom, tj. stworzyć funkcje zwracające obiekt.
  - fromCarthesian (std::string name, double x, double y);
  - fromPolar (std::string name, double r, double phi);
Jeśli w konstruktorach nazwa nie zostanie podana, przyjmuje wartość Vx.
Konstruktory, które nie są jawnie wywoływane w main.cpp powinny być prywatne, podobnie jak współrzędne.

Proszę zaimplementować klasę Vector2D, reprezentującą wektor ma on 2 współrzędne i metody:
   - add, wylicza sumę dwóch wektorów
   - dot, wylicza iloczyn skalarny dwóch wektorów
   - print - wypisuje wektor
   - zwracające obiekt Vector2D na podstawie współrzędnych
  Ponadto możliwe jest zliczanie obiektów klasy.

UWAGA
  - Wymagane jest utworzenie konstruktora przenoszącego oprócz kopiującego ew. konstruktorów delegowanych (za ich brak są odejmowane punkty)
  - konstruktor przenoszący wypisuje wartość wektora przenoszonego do obiektu klasy przed przeniesieniem, jeśli wypiszemy go po przeniesieniu, otrzymamy =(0,0), bo obiekt po prawidłowym przeniesieniu powinien się wyzerować
  - dla ułatwienia proszę skorzystać w konstruktorach z funkcji składowej print()
  - przypominam, że iloczyn skalarny oblicza się ze wzoru x1*x2+y1*y2
  - przeliczanie współrzędych biegunowych na kartezjańskie: [r*cos(α), r*sin(α)], M_PI to wartość liczby pi.
*/

#include <iostream>
#include "Vector2D.h"

Vector2D fun(Vector2D v) {
  return v;
}

int main() {
	{
		Vector2D v1("V1"); //nie ma potrzeby określania
    Vector2D v2 = Vector2D::fromCarthesian("V2", 2., 3.);		// (x, y)
		const Vector2D v3 = Vector2D::fromPolar("V3", 4., 30.);	// (promień, kąt w stopniach)

    v1.print();
		v2.print();
		v3.print();
		std::cout << "\n*** ETAP 1 ***\nLiczba wektorow 2D: " << Vector2D::count << std::endl;

		double prod = v2.dot(v3);
		std::cout << "Iloczyn skalarny v2 i v3: " << prod << std::endl;
		
		const Vector2D v4 = v2.add(v3); 
		v4.print();
		std::cout << "Iloczyn skalarny v4,v2 " << v4.dot(v2) << ", v4,v3: " << v4.dot(v3) << std::endl;

		Vector2D v5 = v3;
		v5.print();
		std::cout << "\n*** ETAP 2 ***\nLiczba wektorow 2D: " << Vector2D::count << std::endl;

		Vector2D v6 (std::move(v4.add(v2)));
    Vector2D v7 = fun(Vector2D::fromCarthesian(2.5,3.5));//fun jest na górze
    Vector2D v8 = std::move(Vector2D("V8"));
		v6.print();
    v7.print();
    v8.print();

    Vector2D v9 = std::move(v7);
    v9.print();
    v7.print();

    std::cout << "Liczba wektorow 2D: " << Vector2D::count << std::endl;
	}
	std::cout << "\n*** ETAP 3 ***\nLiczba wektorow 2D: " << Vector2D::count << std::endl;
}

/* oczekiwany wynik

Obiekt 1: V1=(0,0)
Obiekt 2: V2=(2,3)
Obiekt 3: V3=(3.4641,2)

*** ETAP 1 ***
Liczba wektorow 2D: 3
Iloczyn skalarny v2 i v3: 12.9282
Obiekt 4: Vx=(5.4641,5)
Iloczyn skalarny v4,v2 25.9282, v4,v3: 28.9282
--- kopiowanie Obiekt 3: V3=(3.4641,2)
Obiekt 5: V3=(3.4641,2)

*** ETAP 2 ***
Liczba wektorow 2D: 5
--- przenoszenie Obiekt 6: Vx=(7.4641,8)
--- przenoszenie Obiekt 7: Vx=(2.5,3.5)
--- przenoszenie Obiekt 8: V8=(0,0)
Obiekt 7: Vx=(7.4641,8)
Obiekt 8: Vx=(2.5,3.5)
Obiekt 9: V8=(0,0)
--- przenoszenie Obiekt 8: Vx=(2.5,3.5)
Obiekt 9: Vx=(2.5,3.5)
Obiekt 8: =(0,0)
Liczba wektorow 2D: 9

*** ETAP 3 ***
Liczba wektorow 2D: 0
*/