#include "MyList.h"
#include <iostream>

void prepare(MyList* list){
    list = new MyList;
    list->head = NULL;
}

void add(MyList* list, char* buffer){
    Node* tmp = new Node;
    tmp = list->head;
    if(tmp == NULL){
        strcpy(buffer,tmp->data);
        tmp->next = NULL;
        list->head = tmp;
    }
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = NULL;
    tmp->data = new char(strlen(buffer+1));
    strcpy(buffer,tmp->data);
    list->head = tmp;
}

Node* last(MyList* ptr){
    while(ptr->head->next != NULL)
        ptr->head = ptr->head->next;
    return ptr->head;
}

Node* find(MyList* ptr, char* data){
    while(!strcmp(ptr->head->next->data,data))
        ptr->head = ptr->head->next;
    return ptr->head;
}

bool empty(MyList* ptr){
    if(ptr->head == NULL)
        return true;
    return false;
}


void print(MyList* ptr){
    while(ptr->head->next != NULL){
        std::cout << ptr->head->data;
        ptr->head = ptr->head->next;
    }
}

void clear(MyList* list){
    while(list->head->next != NULL){
        delete list->head->data;
        list->head = list->head->next;
    }
    delete list;
}




