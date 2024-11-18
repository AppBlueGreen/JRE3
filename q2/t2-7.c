#include<stdio.h>

int main() {

    int a = 0, b = 0;
    char array1[256], array2[256];

    while(scanf("%c", &array1[a]) != EOF && array1[a] != '\n') a++;
    array1[a] = '\0';

    while(scanf("%c", &array2[b]) != EOF && array2[b] != '\n') b++;
    array2[b] = '\0';

    char *p = array1, *q = array2;

    int i;
    int result = -1;

    // array1内でarray2を検索
    for(i = 0; i < a; i++) {

        if(*p == *q) { // １文字目が同じであった時
            char *r = p;
            char *s = q;
            int match = 1;

            for(int j = 0; j < b; j++) {
                if(*r != *s) {
                    match = 0;
                    break;
                }
                r++;
                s++;
            }

            if(match) {
                result = i;
                printf("%d\n", result);
                return 0;
            }
        }
        p++;  // 次の文字へ進む
    }

    // 一致が見つからない場合
    printf("%d\n", result);
    return 0;
}
