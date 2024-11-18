#include<stdio.h>

int function(int a, int b) {
    //終端条件
    if(b == 0) return 1;

    //bが奇数の場合
    if(b % 2 == 1) return (function(a, b-1) % 2719) * (a % 2719) % 2719;
    //bが偶数の場合
    else return (function(a, b/2) % 2719) * (function(a, b/2) % 2719) % 2719;
}

int main() {
    int a, b;
    scanf("%d",&a); scanf("%d",&b);

    printf("%d", function(a,b));

    return 0;
}