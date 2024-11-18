#include<stdio.h>
int number = 0;

struct golden {
  long long int a;
  long long int b;  
};

/*multiply_golden: 第１引数と第２引数の積を返す関数*/
struct golden multiply_golden(struct golden x, struct golden y) {

    number++;
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
    int n;
    scanf("%lld %lld", &x.a, &x.b);
    scanf("%d", &n);
    x = power_golden(x, n);
    printf("%lld %lld\n", x.a, x.b);
    printf("%d\n", number);
    return 0;
}