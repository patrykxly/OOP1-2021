#include "MyList.h"
#include <cstring>
#include <iostream>


void Element::init(const char* string){
    this->data = new char[strlen(string)+1];
    strcpy(this->data, string);
    this->next = NULL;
}

void MyList::init(const char* string){
    head = NULL;
    tail = NULL;
    nazwalisty = new char[strlen(string)+1];
    strcpy(nazwalisty,string);
}

void MyList::append(Element* string){
    Element* tmp = new Element;
    tmp->init(string->data);
    if(head = NULL)
        head = tmp; 
    else{
        Element* walker = head;
        while(walker->next)
            walker = walker->next;
        walker->next = tmp;
    }
}

void MyList::append(const char* string){
    Element* tmp = new Element;
    tmp->init(string);
    if(head = NULL)
        head = tmp; 
    else{
        Element* walker = head;
        while(walker->next)
            walker = walker->next;
        walker->next = tmp;
    }
}

bool MyList::isEmpty() const{
    if(head == NULL)
        return true;
    return false;
}

char* MyList::getName() const{
    return head->data;
}

void print(const MyList* lista){
    if(lista->head == NULL)
        return;
    Element* walker = lista->head;
    while(walker->next){
        std::cout << walker->data << " ";
        walker = walker->next;
    }
    std::cout << walker->data << " ";   
}

void MyList::clear(){
    if(head == NULL)
        return;
    Element* iterator = head;
    Element* next = iterator->next;
    while(next){
        delete [] iterator->data;
        delete iterator;
        iterator = next;
        next = next->next;
    }
    delete [] iterator->data;
    delete iterator;
    head = NULL;
}

void MyList::clearList(){
    if(head == NULL)
        return;
    Element* iterator = head;
    Element* next = iterator->next;
    while(next){
        delete [] iterator->data;;
        iterator = next;
        next = next->next;
    }
    delete [] iterator->data;
    head = NULL;
}

void MyList::removeFirst(){
    Element* iterator = head;
    Element* next = iterator->next;
    delete [] iterator->data;
    iterator = next;
}

MyList* MyList::getHead() const{
    return NULL;
}

MyList* MyList::getLast() const{
    return NULL;
}

void MyList::printName(){
    return;
}

