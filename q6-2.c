#include <stdio.h>
#include <string.h>
#define DIGITS 126
char buf1[DIGITS + 2];
char buf2[DIGITS + 2];

int main() {
    int i, j, len_1, len_2;
    int arr1[DIGITS] = {};
    int arr2[DIGITS] = {};
    int arr3[DIGITS*2] = {};

    // 1つ目の数値入力
    fgets(buf1, sizeof(buf1), stdin);
    len_1 = strlen(buf1);
    if (buf1[len_1 - 1] == '\n') {
        buf1[--len_1] = '\0'; // 改行を除去
    }
    for (i = 0; i < len_1; i++)
        arr1[i] = (int)(buf1[len_1 - 1 - i] - '0'); // 逆順に格納

    // 2つ目の数値入力
    fgets(buf2, sizeof(buf2), stdin);
    len_2 = strlen(buf2);
    if (buf2[len_2 - 1] == '\n') {
        buf2[--len_2] = '\0'; // 改行を除去
    }
    for (i = 0; i < len_2; i++)
        arr2[i] = (int)(buf2[len_2 - 1 - i] - '0'); // 逆順に格納

    // 配列同士の乗算処理
    for(i = 0; i < len_2; i++) {

        int carry = 0;

        for(j = 0; j < len_1; j++) { 
            int sum = arr1[j] * arr2[i] + arr3[j+i] + carry;
            arr3[j+i] = sum % 10;
            carry = sum / 10;
        }
        if(carry > 0)
            arr3[j+i] += carry;
    }

    // 0でない桁を探す
    int len_3 = len_1 + len_2;
    int k = len_3;
    while (k > 0 && arr3[k] == 0) k--;

    // 結果の出力
    for (i = k; i >= 0; --i)
        printf("%d", arr3[i]);
    printf("\n");

    return 0;
}
