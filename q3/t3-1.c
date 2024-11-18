#include<stdio.h>

struct golden {
    long long int a;
    long long int b;
};

/*triple_golden: 第1引数を3倍した数を返すstruct golden型の関数*/
struct golden triple_golden(struct golden x) {

    struct golden y;
    y.a = (x.a)*3;
    y.b = (x.b)*3;

    return y;
}

int main() {

    struct golden x;
    scanf("%lld %lld", &x.a, &x.b);
    x = triple_golden(x);
    printf("%lld %lld\n", x.a, x.b);
    return 0;
}