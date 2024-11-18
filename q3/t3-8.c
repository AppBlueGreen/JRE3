#include<stdio.h>

struct golden {
    long long int a;
    long long int b;
};

/*multiply_golden: 第１引数と第２引数の積を返す関数*/
struct golden multiply_golden(struct golden x, struct golden y) {

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

            struct golden w_0 = (multiply_golden(x, power_golden(x, n-1)));
            w_0.a %= 2719; w_0.b %= 2719;
            return w_0;

        }else {//nが偶数の時

            struct golden w = (power_golden(x, n/2));
            w.a %= 2719; w.b %= 2719;
            w =  multiply_golden(w, w);
            w.a %= 2719; w.b %= 2719;
            return w ;
        }
    }
}

int main() {

    struct golden x;
    x.a = 1, x.b = -1;

    int n;
    scanf("%d", &n);

    if(n == 1) {
        printf("%d\n", 1); // F_1

    }  else {
        x = power_golden(x, n-1);
        if(x.a < 0) {
            x.a += 2719;
        }
        printf("%lld\n", x.a); // F_n
    }

    return 0;
}