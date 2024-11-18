#include<stdio.h>

int main() {

    char array[1000];

    int i = 1;

    while(scanf("%c", &array[i]) != EOF) i++;
    array[i] = '\0';

    for(int i = 2; array[i] != '\0'; i++) {

        int flag = 1;

        for(int j = 2; j < i; j++) {

            if(i % j == 0) {
              
                flag = 0; 
                break;
            }
        }

        if(flag) printf("%c",array[i]);
    }

    return 0;
}