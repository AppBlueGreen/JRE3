#include<stdio.h>

struct golden {
    long long int a;
    long long int b;
};

struct golden multiply_golden(struct golden x, struct golden y) {

    struct golden z;
    z.a = x.a * y.a + x.b * y.b;
    z.b = x.a * y.b + y.a * x.b + x.b * y.b;
    return z;
}

int main() {

    struct golden x, y;
    scanf("%lld %lld", &x.a, &x.b);
    scanf("%lld %lld", &y.a, &y.b);
    x = multiply_golden(x, y);
    printf("%lld %lld\n", x.a, x.b);
    return 0;
}