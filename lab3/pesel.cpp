#include <cstdio>
#include <iostream>
#include "pesel.h"
#include <cstring>

int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int months[12][3] = { {1,21,41}, {2,22,42}, {3,23,43}, {4,24,44},{5,25,45},{6,26,46},{7,27,47},{8,28,48},{9,29,49},{10,30,50},{11,31,51},{12,32,52}};

bool leapYear(int year) { //funkcja pomocnicza do sprawdzania czy rok jest przestepny 
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}


void printPesel(int* arr){
    for(int i = 0; i < 11; i++)
        std::cout << arr[i];
}

int getCtrlNumber(int* arr){
    return arr[10];
}

int getDay(int* arr){
    int k = arr[4];
    int l = arr[5];
    return k*10+l;
}

int getMonth(int* arr){
    for(int i = 0; i < 12;i++)
        for(int j = 0; j < 3; j++){
            if(months[i][j] == arr[2]*10+arr[3])
                return i+1;
        }
    return 0; 
}
int getYear(int* arr){
    for(int i = 0; i < 12;i++)
        for(int j = 0; j < 3; j++){
            if(months[i][j] == arr[2]*10+arr[3]){
                if(months[i][j] <= 12)
                    return 1900+(arr[0]*10+arr[1]);
                if(months[i][j] >= 21 && months[i][j] <= 32)
                    return 2000+(arr[0]*10+arr[1]);
                if(months[i][j] >= 41 && months[i][j] < 52)
                    return 2100+(arr[0]*10+arr[1]);
            }
        }
    return 0;
}

int checkCtrlNum(int* arr){
    int ctrlnum = getCtrlNumber(arr);
    int checkingnum = (arr[0] * 1 + arr[1] * 3 + arr[2] * 7 + arr[3] * 9 + arr[4] * 1 + arr[5] * 3 + arr[6] * 7 + arr[7] * 9 + arr[8] * 1 + arr[9] * 3)%10;
    if(ctrlnum == checkingnum)
        return 1;
    return 0;
}

int PeselValidator(const char *tab, int* arr){ //sprawdzanie czy pesel jest w prawidlowej formie
    if(strlen(tab) != 11)
        return 0;
    for(int i = 0;i<strlen(tab);i++){
        arr[i] = tab[i] - 48;
    }
    if(getDay(arr) && getMonth(arr) && getYear(arr) && checkCtrlNum(arr))
        return 1;
    return 0;
}