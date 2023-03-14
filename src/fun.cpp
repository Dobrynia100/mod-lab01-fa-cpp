// Copyright 2022 UNN-IASR
#include <iostream>
#include <cstring>
#include <cmath>

#include "fun.h"

unsigned int faStr1(const char* str) {//нет цифр
    int  N= 0;
    bool let = false, num = false;
    for (int i = 0; i < strlen(str); i++){
        if (isalpha(str[i])) {
            let = true;
        }
        if (isdigit(str[i])) {
            num = true;
        }
        if (isspace(str[i]&let)) {
            if (let && !num) {
                N++;
            }
            let = false;
            num = false;
        }        
    }
    return N;
}
unsigned int faStr2(const char* str) {//заглав лат
    int N = 0;
    bool first = true;  
    for (int i = 0; i < strlen(str); i++) {
        if (isupper(str[i])&& first) {
            first = false;
            N++;
        }
        if (isspace(str[i])) {
            first = true;
        }
    }
    return N;
}
unsigned int faStr3(const char* str) {//сред длин
    int Nwords = 0,Nlet;
    bool word = false;
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            Nlet++;
            word = true;
        }
        if (isspace(str[i])&& word) {
            Nwords++;
            word = false;
        }
    }
    float lenght = static_cast<double>(Nlet) / Nwords;
    return round(lenght);
}