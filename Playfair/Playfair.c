//
// Created by vioan12 on 18.11.2018.
//

#include "Cifruri.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
        if (!isUppercaseLetter(*p)) {
            return 0;
        }
        p++;
    }
    return 1;
}

char* removeDuplicateCharacters(char* text){
    char *p,*newText,*buffer,*q;
    size_t bufferSize = strlen(text) + 1;
    buffer = (char*)malloc(bufferSize*sizeof(char));
    strcpy(buffer,text);
    p=buffer;
    while(*(p+1)!='\000') {
        q=strchr(p+1,*p);
        while(q){
            strcpy(q,q+1);
            q=strchr(p+1,*p);
        }
        p++;
    }
    size_t newTextSize = strlen(buffer) + 1;
    newText = (char*)malloc(newTextSize*sizeof(char));
    strcpy(newText,buffer);
    free(buffer);
    return newText;
}

void mappingMatrix(char *key, char translateLetter){
    char *p,*newKey;
    newKey = removeDuplicateCharacters(key);
    p = newKey;
    int x=0;
    for(int i=0; i<matrixSize; i++){
        for(int j=0; j<matrixSize; j++){
            if(*p!='\000') {
                alphabetMatrix[i][j] = *p;
                p++;
            } else{
                while (strchr(newKey,alphabetUppercase[x])){
                    x++;
                }
                if(alphabetUppercase[x] != translateLetter){
                    alphabetMatrix[i][j] = alphabetUppercase[x];
                }else{
                    x++;
                    alphabetMatrix[i][j] = alphabetUppercase[x];
                }
                x++;
            }
        }
    }
}

char* replaceCharacter(char oldCharacter, char newCharacter, char *text)
{
    char *newText, *p;
    size_t newTextSize = strlen(text) + 1;
    newText = (char*)malloc(newTextSize*sizeof(char));
    strcpy(newText,text);
    p=newText;
    while(*p!='\000') {
        if(*p==oldCharacter){
            *p=newCharacter;
        }
        p++;
    }
    return newText;
}

int minimum(int firstNumber, int secondNumber){
    if(firstNumber<secondNumber){
        return firstNumber;
    } else {
        return secondNumber;
    }
}

int maximum(int firstNumber, int secondNumber){
    if(firstNumber>secondNumber){
        return firstNumber;
    } else {
        return secondNumber;
    }
}

struct Slice* sliceExtract(char firstLetter, char secondLetter){
    struct Slice *slice = (struct Slice*)malloc(sizeof(struct Slice));
    int xFirstLetter,yFirstLetter,xSecondLetter, ySecondLetter;
    xFirstLetter=yFirstLetter=xSecondLetter=ySecondLetter=-1;
    for(int i=0; i<matrixSize; i++){
        for(int j=0; j<matrixSize; j++){
            if(firstLetter==alphabetMatrix[i][j]){
                xFirstLetter = i;
                yFirstLetter = j;
            }
            if(secondLetter==alphabetMatrix[i][j]){
                xSecondLetter = i;
                ySecondLetter = j;
            }
        }
    }
    if(xFirstLetter != -1 && yFirstLetter != -1 && xSecondLetter != -1 && ySecondLetter != -1) {
        slice->nrRows = (int*)malloc(sizeof(int));
        slice->nrColumns = (int*)malloc(sizeof(int));
        *slice->nrRows = abs(xFirstLetter-xSecondLetter)+1;
        *slice->nrColumns = abs(yFirstLetter-ySecondLetter)+1;
        size_t sliceMatrixSize = (size_t)(*slice->nrRows)*(*slice->nrColumns) + 1;
        slice->matrix = (char*)malloc(sliceMatrixSize*sizeof(char));
        char *p;
        p=slice->matrix;
        if(*slice->nrRows>1 && *slice->nrColumns>1){
            for (int i = minimum(xFirstLetter, xSecondLetter); i <= maximum(xFirstLetter, xSecondLetter); i++) {
                for (int j = minimum(yFirstLetter, ySecondLetter); j <= maximum(yFirstLetter, ySecondLetter); j++) {
                    *p = alphabetMatrix[i][j];
                    p++;
                }
            }
        } else{
            if(firstLetter == secondLetter){
                *p = firstLetter;
            }
            if(*slice->nrRows==1) {
                for (int i = minimum(xFirstLetter, xSecondLetter); i <= maximum(xFirstLetter, xSecondLetter); i++) {
                    for (int j = 0; j < matrixSize; j++) {
                        *p = alphabetMatrix[i][j];
                        p++;
                    }
                }
            }
            if(*slice->nrColumns==1) {
                for (int i = 0; i < matrixSize; i++) {
                    for (int j = minimum(yFirstLetter, ySecondLetter); j <= maximum(yFirstLetter, ySecondLetter); j++) {
                        *p = alphabetMatrix[i][j];
                        p++;
                    }
                }
            }
        }
        return slice;
    }
    return NULL;
}

struct TwoLetters* twoLettersExtract(struct Slice *slice, char firstLetter, char secondLetter, int sign)
{
    if(*slice->nrRows==1){

    }
    if(*slice->nrColumns==1){

    }
    if(*slice->nrRows==1 && *slice->nrColumns==1){

    }
}

char* playfairEncrypt(char *key, char translateLetter, char intoLetter, char *text ){
    if(textIsValid(key) && isUppercaseLetter(translateLetter) && isUppercaseLetter(intoLetter) && textIsValid(text)){
        char *newText,*r;
        mappingMatrix(replaceCharacter(translateLetter,intoLetter,key),translateLetter);
        size_t newTextSize = strlen(text) + 1;
        newText = (char*)malloc(newTextSize*sizeof(char));
        r=newText;
        struct Slice *slice;
        struct TwoLetters *twoLetters;
        char *p,*q;
        p=text;
        q=p+1;
        while(*(p+2)!='\000' && *(q+1)!='\000') {
            slice=sliceExtract(*p,*q);
            p = p + 2;
            q = q + 2;
            if(*(p)=='\000') {
                break;
            }
            if(*(q)=='\000') {
                break;
            }
        }
        if(isUppercaseLetter(*p)){
            if(isUppercaseLetter(*q)){
                slice=sliceExtract(*p,*q);
            } else {
                slice=sliceExtract(*p,'X');
            }
        }
    }
    return NULL;
}