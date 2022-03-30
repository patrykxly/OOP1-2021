#ifndef PESEL_H
#define PESEL_H

int PeselValidator(const char *tab, int* arr); //sprawdzanie czy pesel jest w dobrej formie
void printPesel(int* arr); //wypisywanie peselu 
int getCtrlNumber(int* arr); //wypisywanie numeru kontrolnego
int getDay(int* arr); //wypisywanie dnia urodzenia
int getMonth(int* arr); //wypisywanie miesiaca urodzenia
int getYear(int* arr); // wypisywanie roku urodzenia
//ponizej funkcje pomocnicze:
bool leapYear(int year); //spradzanie czy rok jest przestepny
int checkCtrlNum(int* arr); //sprawdzanie czy liczba kontrola jest prawidlowa

#endif