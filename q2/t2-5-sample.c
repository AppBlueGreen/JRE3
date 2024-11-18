#include<stdio.h>
#include<string.h>
#define MAXLEN 128
char buf[MAXLEN+2];

int main() {

    char *p;

    while(fgets(buf, sizeof(buf), stdin) != NULL) {

        p = strchr(buf, '\n');

        if(p != NULL) *p = '\0';
        else {
            printf("\n");
            continue;
        }

        // 各文字列の数字を一つずつ取り出して#に変える工程
        char *q = buf;

        int i;
        char bufpri[80];
        for(int k = 0; k < 80; k++) bufpri[k] = ' ';

        while(sscanf(q, "%d", &i) != '\n') {

            bufpri[i] = '#';
            
            q = strchr(q, ' ');

            if(q == NULL) break;

            else while(*q == ' ') ++q;

        }
        //　ここまで

        for(int i = 80; bufpri[i] == ' ';) i--; //最後の#の位置を特定

        // if(i == -1) bufpri[0] = '\n'; //何も数字がない行の処理
        bufpri[i+1] = '\n';

        // printf("%s\n", bufpri);
        for(int j = 0; bufpri[j] != '\n'; j++) {

            printf("%c",bufpri[j]);

        }

        printf("\n");

    }

    return 0;
}