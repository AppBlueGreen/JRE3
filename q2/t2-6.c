#include<stdio.h>

int main() {

    char array[128];

    int a = 0, result = 0;
    
    while(scanf("%c", &array[a]) != EOF && array[a] !='\n') a++;
    array[a] = '\0';

    char *p = array;

    int i;
    for(i = 0; i < a-1; i++) {

        if(*p == '@') {

            char *q = p+1;

            if(*q == '@') {
    
                result = i;
                printf("%d",result);
                return 0;
            }
        }
        p++;
    }

    result = i+1;
    printf("%d",result);
    return 0;
}