#include<stdio.h>
#include<stdlib.h>
char buf[512];

// 入れ子構造になっているかチェックする関数
int check(char c, int i) {

    char expected, c1, c2, c3;

    if(c == '('){expected = ')'; c1 = '}'; c2 = ']'; c3 = '>';}

    else if(c == '{'){expected = '}'; c1 = ')'; c2 = ']'; c3 = '>';}

    else if(c == '['){expected = ']'; c1 = ')'; c2 = '}'; c3 = '>';}

    else if(c == '<'){expected = '>'; c1 = ')'; c2 = '}'; c3 = ']';}

    else {return 0;}

    for(int j = i + 1; buf[j] != '\0'; j++) {

        if(buf[j] == '(' || buf[j] == '{' || buf[j] == '[' || buf[j] == '<') {
            j += check(buf[j], j);

        } else if(buf[j] == c1 || buf[j] == c2 || buf[j] == c3) {
            printf("Bad\n");
            exit(1);

        }else if(buf[j] == expected) {
            return j - i;

        }else {
            continue;
        }
    }

    printf("Bad\n");
    exit(1);
}

int main() {
    
    fgets(buf, sizeof(buf), stdin);

    for(int i = 0; buf[i] != '\0'; i++) { //改行文字を除去
        if(buf[i] == '\n') {
            buf[i] = '\0';
            break;
        }
    }

    for(int i = 0; buf[i] != '\0'; i++) {

        if(buf[i] == '(' || buf[i] == '{' || buf[i] == '[' || buf[i] == '<') {

            i += check(buf[i], i);

        } else if (buf[i] == ')' || buf[i] == '}' || buf[i] == ']' || buf[i] == '>') {
            printf("Bad\n");
            return 1;
        }
        
    }

    printf("Good\n");
    return 0;
}