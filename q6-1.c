#include<stdio.h>
#define DIGITS 126
char buf[DIGITS+2];

int main() {
    int i, len_1, len_2;
    int arr1[DIGITS] = {};
    int arr2[DIGITS] = {};
    int arr3[DIGITS+1] = {}; //繰り上げも考え127桁まで保持

    i = 0;
    fgets (buf, sizeof(buf), stdin); //改行までの文字列をbufに格納
    while(buf[i] != '\n') ++i; //bufの改行の位置を探す(入力の長さを把握)
    len_1 = i; //改行の位置をlenに保存
    for(i = 0; i < len_1; i++)
        arr1[i] = (int)(buf[len_1-1-i]-'0'); //整数型として配列に格納

    i = 0;
    fgets (buf, sizeof(buf), stdin); //改行までの文字列をbufに格納
    while(buf[i] != '\n') ++i; //bufの改行の位置を探す(入力の長さを把握)
    len_2 = i; //改行の位置をlenに保存
    for(i = 0; i < len_2; i++)
        arr2[i] = (int)(buf[len_2-1-i]-'0'); //整数型として配列に格納

    for(i = 0; i < DIGITS; i++) {
        int digit = 0;
        int carry = 0;

        if(arr1[i] + arr2[i] >= 10) { //繰上げしそうな場合
            carry = arr1[i] + arr2[i];
            carry /= 10;
            arr3[i+1] = carry;
        }

        digit = arr1[i] + arr2[i];
        digit %= 10;
        arr3[i] = digit;
    }

    //0でない桁を探す
    for(int k = DIGITS+1; arr3[k] == 0; --k)

    for(int i = k; i >= 0; --k)
        printf("%d", arr3[i]);

    printf("\n");
    return 0;
}