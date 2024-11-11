#include<stdio.h>
#define DIGITS 126
char buf1[DIGITS+2];
char buf2[DIGITS+2];

int main() {
    int i, len_1, len_2;
    int arr1[DIGITS] = {};
    int arr2[DIGITS] = {};
    int arr3[DIGITS+1] = {}; //繰り上げも考え127桁まで保持

    i = 0;
    fgets (buf1, sizeof(buf1), stdin); //改行までの文字列をbufに格納
    while(buf1[i] != '\n') ++i; //bufの改行の位置を探す(入力の長さを把握)
    len_1 = i; //改行の位置をlenに保存
    for(i = 0; i < len_1; i++)
        arr1[i] = (int)(buf1[len_1-1-i]-'0'); //整数型として配列に格納

    i = 0;
    fgets (buf2, sizeof(buf2), stdin); //改行までの文字列をbufに格納
    while(buf2[i] != '\n') ++i; //bufの改行の位置を探す(入力の長さを把握)
    len_2 = i; //改行の位置をlenに保存
    for(i = 0; i < len_2; i++)
        arr2[i] = (int)(buf2[len_2-1-i]-'0'); //整数型として配列に格納

    int carry = 0;
    for(i = 0; i < DIGITS; i++) {
        
        int sum = arr1[i] + arr2[i]  + carry;
        arr3[i] = sum % 10;
        carry = sum / 10;
    }
    arr3[DIGITS] = carry;

    //0でない桁を探す
    int k = DIGITS;
    while(k > 0 && arr3[k] == 0) k--;

    for(i = k; i >= 0; --i)
        printf("%d", arr3[i]);
    printf("\n");
    return 0;
}