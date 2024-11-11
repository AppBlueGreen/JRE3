#include <stdio.h>
#include <string.h>
#define DIGITS 126
char buf1[DIGITS + 2];
char buf2[DIGITS + 2];

int main() {
    int i, len_1, len_2;
    int arr1[DIGITS] = {};
    int arr2[DIGITS] = {};
    int arr3[DIGITS + 1] = {}; // 繰り上げも考え127桁まで保持

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

    // 配列同士の加算処理
    int carry = 0;
    int max_len = len_1 > len_2 ? len_1 : len_2;
    for (i = 0; i < max_len || carry > 0; i++) {

        int sum = arr1[i] + arr2[i] + carry;
        arr3[i] = sum % 10;
        carry = sum / 10;
    }

    // 0でない桁を探す
    int k = max_len;
    while (k > 0 && arr3[k] == 0) k--;

    // 結果の出力
    for (i = k; i >= 0; --i)
        printf("%d", arr3[i]);
    printf("\n");

    return 0;
}
