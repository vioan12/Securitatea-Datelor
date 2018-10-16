#include <stdio.h>
#include "Cifruri.c"

int main() {
    printf("%s\n",caesarEncrypt(118,"Anaaremeresizambile"));
    printf("%s\n",caesarDecrypt(25,"Zmzzqdldqdrhyzlahkd"));
    return 0;
}