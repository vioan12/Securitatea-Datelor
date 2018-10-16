#include "Cifruri.h"
#include <stdlib.h>
#include <string.h>

int letterToPosition (char letter) {
    for (int i = 0; i < alphabetSize; ++i) {
        if (letter == alphabetLowercase[i] || letter == alphabetUppercase[i]) {
            return i;
        }
    }
    return -1;
}

char positionToLowercaseLetter(int position){
    if(position / alphabetSize  > 0){
        position = position % alphabetSize;
    }
    if(position < 0) {
        position = alphabetSize - abs(position);
    }
    return alphabetLowercase[position];
}

char positionToUppercaseLetter(int position){
    if(position>=alphabetSize){
        position = position % alphabetSize;
    }
    return alphabetUppercase[position];
}

int isLowercaseLetter (char letter){
    if(letter >= 'a' && letter <= 'z'){
        return 1;
    } else {
        return 0;
    }
}

int isUppercaseLetter (char letter){
    if(letter >= 'A' && letter <= 'Z'){
        return 1;
    } else {
        return 0;
    }
}

int textIsValid(char* text) {
    char *p;
    p = text;
    while(*p!='\000') {
        if (!(isLowercaseLetter(*p) || isUppercaseLetter(*p))) {
            return 0;
        }
        p++;
    }
    return 1;
}

char* caesarUniversal(int key, char* text, int sign){
    if(textIsValid(text)) {
        char *newText, *pNewText, *pText;
        size_t newTextSize = strlen(text) + 1;
        newText = (char*)malloc(newTextSize*sizeof(char));
        key = abs(key);
        if (key >= alphabetSize) {
            key = key % alphabetSize;
        }
        pText = text;
        pNewText = newText;

        while(*pText!='\000'){
            if(isLowercaseLetter(*pText)){
                *pNewText = positionToLowercaseLetter(letterToPosition(*pText) + (key * sign));
            }
            if(isUppercaseLetter(*pText)){
                *pNewText = positionToUppercaseLetter(letterToPosition(*pText) + (key * sign));
            }
            pText++;
            pNewText++;
        }
        return newText;
    }
    return NULL;
}

char* caesarEncrypt(int key, char* text) {
    return caesarUniversal(key, text, 1);
}

char* caesarDecrypt(int key, char* text) {
    return caesarUniversal(key, text, -1);
}

