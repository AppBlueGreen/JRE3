#include<stdio.h>
#include<string.h>
#include "/ced-home/staff/24jr3/include/jr3.h"

#define SIZE 101

int hash (char *s) {
    int arrayNumber = strlen(s);
    int hash = 0;
    for (int i = 0; i < arrayNumber; i++) {
        hash = (hash * 128 + s[i]) % SIZE;
    }
    return hash;
}

int main () {
    char s[32];
    if (scanf("%[^\n]", s) == EOF) {
        fprintf(stderr, "No target text string was specified.\n");
        return 1;
    }
    printf("%d\n", hash(s));
    return 0;
}