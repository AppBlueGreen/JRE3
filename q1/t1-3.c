#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[128];

    fgets(str, 128, stdin);
    printf("%s", str);
    return 0;
}