// Copyright 2022 UNN-IASR
#include <iostream>
#include <cstring>
#include <cmath>

#include "fun.h"

unsigned int faStr1(const char* str) {
    int  N = 0;
    bool let = false, num = false;
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            let = true;
        }
        if (isdigit(str[i])) {
            num = true;
        }
        if (isspace(str[i]) && let) {
            if (let && !num) {
                N++;
            }
            let = false;
            num = false;
        }
    }
    if (let && !num) {
        N++;
    }
    return N;
}
unsigned int faStr2(const char* str) {
    int N = 0;
    bool first = true, check = false;
    for (int i = 0; i < strlen(str); i++) {
        if (isupper(str[i]) && first) {
            first = false;
        }
        if (!isalpha(str[i]) && !isspace(str[i]))check = true;
        if (isspace(str[i])) {
            if (!check && !first)N++;
            first = true;
            check = false;
        }
    }
    if (!check && !first)N++;
    return N;
}
unsigned int faStr3(const char* str) {
    int Nwords = 0, Nlet = 0;
    bool word = false;
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            Nlet++;
            word = true;
        }
        if (isspace(str[i]) && word) {
            Nwords++;
            word = false;
        }
    }
    if (word)Nwords++;
    float lenght = static_cast<double>(Nlet) / Nwords;
    return round(lenght);
}
