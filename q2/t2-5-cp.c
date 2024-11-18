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

        char *q = buf;

        int i;
        char bufpri[80];
        for(int k = 0; k < 80; k++) bufpri[k] = ' ';

        int hasNumber = 0;  // 数字があるかどうかを判定するフラグ

        while(sscanf(q, "%d", &i) == 1) {  // 数字が見つかれば実行

            bufpri[i] = '#';  // 数字に対応する場所に#をセット
            hasNumber = 1;    // 数字があったのでフラグを1に

            q = strchr(q, ' ');  // 次のスペースを探す

            if(q == NULL) break;

            else while(*q == ' ') ++q;  // 次の数字の位置に移動

        }

        // 数字がない行は改行だけ出力して次の行へ
        if (!hasNumber) {  
            printf("\n");
            continue;
        }

        // 最後の#の位置を特定して出力
        for(int i = 80; bufpri[i] == ' ';) i--; 
        bufpri[i+1] = '\n';

        for(int j = 0; bufpri[j] != '\n'; j++) {
            printf("%c", bufpri[j]);  // bufpriの内容を出力
        }

        printf("\n");  // 改行を出力

    }

    return 0;
}
