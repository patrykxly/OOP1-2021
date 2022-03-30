#ifndef MYLIST_H
#define MYLIST_H
#include <cstring>

struct Node{
    char* data;
    Node* next;
};

struct MyList{
    Node* head;
};

void prepare(MyList* list); //funkcja przygotowujaca liste (alokowanie pamiec i ustawienie head na null)
void add(MyList* list, char* buffer); //dodawanie elementow do listy
Node* last(MyList* ptr); //wyszukiwanie ostatniego elementu listy
Node* find(MyList* ptr, char* data); //znajdowanie elementu w liscie
bool empty(MyList* ptr); //sprawdzanie czy lista jest pusta (1 = pusta, 0 = niepusta)
void print(MyList* ptr); //drukowanie listy
void clear(MyList* list); //czyszczenie pamieci
#endif