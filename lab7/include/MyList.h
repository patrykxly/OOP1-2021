#ifndef MYLIST_H
#define MYLIST_H

class Element{
    public:
        char* data;
        Element* next;
        void init(const char* string); //alokowanie pamieci dla elementu, ustawianie wskaznika next
};

class MyList{
    public:
        char* nazwalisty;
        Element* head;
        Element* tail;
        void init(const char* string); //alokowanie pamieci dla listy, ustawianie wskaznikow
        void clear(); //czyszczenie elementow listy i listy
        void clearList(); //czyszczenie elementow listy bez usuwania jej
        void append(Element* string); //dodawanie napisu z elementu do listy 
        void append(const char* string); //dodawanie napisu do listy
        void removeFirst(); //usuwanie pierwszego elementu listy
        char* getName() const; //pokazywanie nazwy listy
        void printName(); //funkcja do pokazywania ostatniego lub pierwszego elementu lity
        MyList* getHead() const; //dostawanie sie do heada listy 
        MyList* getLast() const; //dostawanie sie do konca listy 
        bool isEmpty() const; //sprawdzanie czy lista jest pusta
};   

void print(const MyList* lista); //drukowanie listy

#endif