#include<stdio.h>
int addNumber = 0;
int multiNumber = 0;

struct golden {
    long long int a;
    long long int b;
};

/*multiply_golden: 第１引数と第２引数の積を返す関数*/
struct golden multiply_golden(struct golden x, struct golden y) {

    multiNumber += 5;
    addNumber += 3;

    struct golden z;
    z.a = x.a * y.a + x.b * y.b;
    z.b = x.a * y.b + y.a * x.b + x.b * y.b;
    return z;
}

/*power_golden: 第１引数の第２引数乗を返す関数*/
struct golden power_golden(struct golden x, int n) {

    struct golden z;
    if(n == 0) {
        z.a = 1; z.b = 0;
        return z;
    }
    else {
        if(n % 2 == 1) {//nが奇数の時
            return multiply_golden(x, power_golden(x, n-1));

        }else {//nが偶数の時
            struct golden w = power_golden(x, n/2);
            return multiply_golden(w, w);
        }
    }
}

int main() {

    struct golden x;
    x.a = 1, x.b = -1;

    int n;
    scanf("%d", &n);

    if(n == 1) {
        printf("%d\n", 0);
        printf("%d\n", 0);
        printf("%d\n", 1); // F_1
        return 0;
    } 
    else {
        x = power_golden(x, n-1);
        printf("%d\n", addNumber);
        printf("%d\n", multiNumber);
        printf("%lld\n", x.a); // F_n
        return 0;
    }
}
