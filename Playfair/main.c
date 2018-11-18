#include <stdio.h>
#include "Playfair.c"

int main() {
    printf("%s\n",playfairEncrypt("POWERFUL",'J','I',"UQGHXXFGSSDI"));
    return 0;
}