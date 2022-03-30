/* Celem zadania jest przećwiczenie operatora[] oraz
   operatora() i jego wykorzystania w połączeniu z std::function.

   Proszę zdefiniować klasy reprezentujące funkcje matematyczne:
   - Linear -- funkcja liniowa a*x+b
   - Pow -- potęga x^n
   - Sin -- sin(a*x+b)
   - Abs -- |x|
  
   Mają one przeciążony operator(), który zwraca odpowiednią wartość funkcji.
   Proszę zdefiniować je we wspólnych plikach funtions.h i funtions.cpp
   Prosze zdefiniować tylko niezbędne konstruktory.
  
   Proszę także zaimplementować klasę FunctionVector, która przyjmuje i przechowuje obiekty funkcyjne oraz pozwala na rekursywne obliczenie wyniku kolejnych wywołań, np. dla trzech funkcji w wektorze:
      FunctionVector f;
      f+=f1; f+=f2; f+=f3  //  f = [f1, f2, f3]
      f.calc(x) = f3 (f2 (f1(x)))
   oraz zwraca wyniki pośrednich obliczeń przez operator[] (poza wersją BASIC)
      f[0] = f1(x)
      f[1] = f2 (f1(x))
      f[2] = f3 (f2 (f1(x)))
   UWAGA: zalecane użycie std::vector

 * Pliku main.cpp, NIE WOLNO modyfikować bez zgody prowadzącego.
*/ 

#include "functions.h"
#include "functionVector.h"

#include <iostream>
#define _USE_MATH_DEFINES

double my_abs(double x){
	return x>=0 ? x : -x;
}

int main ()
{  
  std::cout <<std::endl;
  Linear lin(-0.25, -1.);
  std::cout << "lin(x) = " << lin << std::endl;
  const Pow exp; // to samo co exp(2)
  const Abs abs;
  Cos cosinus(M_PI, M_PI/3.);
  std::cout << "exp(x) = " << exp << std::endl;

  double x = 10;
  std::cout << "\n*** Wyniki pojedynczych funkcji dla x=10 *** \n";
  std::cout << "Cosinus:\t\t\t" << cosinus(x) << std::endl; 
  std::cout << "Potega druga:\t\t" << exp(x) << std::endl; 
  std::cout << "Funkcja liniowa:\t" << lin(x) << std::endl; 
  std::cout << "Wartosc bezwzgledna: " << abs(-x) << std::endl; 
  
  FunctionVector fs;
  fs += cosinus; 
  fs += abs;
  fs += exp;
  fs += lin;
  fs += my_abs;
  
  //test operatora () do zagnieżdżania funkcji
  double result1 = fs.eval(x);
  double result2 = abs(lin(exp(abs(cosinus(x)))));
  std::cout << "\n*** Obliczamy abs(-0.25*exp(abs(cos(pi*x+pi/3))+1) *** \n";
  std::cout << "--- Dla x=10 :\t" << result1 << ", " << result2 << std::endl; 

  x = 0.5;
  std::cout << "--- Dla x=0.5 :\t" << fs.eval(x) << ", " << my_abs(lin(exp(abs(cosinus(x))))) << std::endl;

#ifndef BASIC
  // test operatora [] zwracającego wyniki pośrednich obliczeń 
  std::cout << "\n*** Wyniki posrednie dla x=0.5: *** \n";
  double cosx = cosinus(x);
  std::cout << "--- f1 = cos(pi*x+pi/3): " << cosx << ", " << fs[0] << std::endl; 
    std::cout << "--- f2 = abs(f1):\t\t" << abs(cosx) << ", " << fs[1] << std::endl; 
  std::cout << "--- f3 = exp(f2):\t\t" << exp(abs(cosx)) << ", " << fs[2] << std::endl; 
  std::cout << "--- f4 = -0.25*f3+1:\t" << lin(exp(abs(cosx))) << ", " << fs[3] << std::endl; 
#endif

  fs.clear();
  x=-2;
  Pow exp3(3);
  Linear lin2(0.5, -3.5);
  fs += exp3;
  fs += lin2;
  fs += exp;

  std::cout << "\n*** Obliczamy abs(0.5*exp(x^3)-3.5) *** \n" ;
  std::cout << "--- Dla x=-2 :\t" << fs.eval(x) << ", " << exp(lin2(exp3(x))) << std::endl;

#ifndef BASIC
  std::cout << "f1 = " << exp3(x) << ", " << fs[0] << std::endl; 
  std::cout << "f2 = " << lin2(exp3(x)) << ", " << fs[1] << std::endl; 
  std::cout << "f3 = " << exp(lin2(exp3(x))) << ", " << fs[2] << std::endl; 
#endif

std::cout << std::endl; 
return 0;
}

/* Oczekiwany wynik: ./main

lin(x) = -0.25*x-1
exp(x) = x^2

*** Wyniki pojedynczych funkcji dla x=10 *** 
Cosinus:            0.5
Potega druga:       100
Funkcja liniowa:    -3.5
Wartosc bezwzgledna: 10

*** Obliczamy abs(-0.25*exp(abs(cos(pi*x+pi/3))+1) *** 
--- Dla x=10 :  1.0625, 1.0625
--- Dla x=0.5 : 1.1875, 1.1875

*** Wyniki posrednie dla x=0.5: *** 
--- f1 = cos(pi*x+pi/3): -0.866025, -0.866025
--- f2 = abs(f1):       0.866025, 0.866025
--- f3 = exp(f2):       0.75, 0.75
--- f4 = -0.25*f3+1:    -1.1875, -1.1875

*** Obliczamy abs(0.5*exp(x^3)-3.5) *** 
--- Dla x=-2 :  56.25, 56.25
f1 = -8, -8
f2 = -7.5, -7.5
f3 = 56.25, 56.25

*/