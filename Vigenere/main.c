#include <stdio.h>
#include "Vigenere.c"

int main() {
    printf("%s\n",vigenereDecrypt("dintnofnthtittf","smbiystsflwqhvwhiobywyllvfmmbrhanvu"));
    printf("%s\n",vigenereEncrypt("DINTNOFNTHTITTF","PEOPUEOFMEDIHCREABIUITYSOMETIMESACQ"));
    return 0;
}