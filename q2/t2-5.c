#include<stdio.h>
#include<string.h>
#define MAXLEN 128
char buf[MAXLEN+2];

int main() {

    char *p;

    while(fgets(buf, sizeof(buf), stdin) != NULL) {

        p = strchr(buf, '\n');

        if(p != NULL) *p = '\0';

        // 各文字列の数字を一つずつ取り出して#に変える工程
        char *q = buf;

        int i;
        char bufpri[80];
        for(int k = 0; k < 80; k++) bufpri[k] = ' ';

        int last_hash_pos = -1;  // 最後の # の位置を記録

        while(sscanf(q, "%d", &i) != EOF) {

            if(i >= 0 && i < 80) {
                bufpri[i] = '#';
                last_hash_pos = i;  // # が配置された位置を記録
            }
            
            q = strchr(q, ' ');

            if(q == NULL) {
                break;
            } else {
                while(*q == ' ') ++q;
            }
        }

        // 最後に # が配置された位置までを表示し、その後改行
        if (last_hash_pos != -1) {
            bufpri[last_hash_pos + 1] = '\0';  // 最後の # の直後に終端を設定
        } else {
            bufpri[0] = '\0';  // もし # がなければ空文字列を設定
        }

        printf("%s\n", bufpri);  // 結果を出力
    }

    return 0;
}
