#include<stdio.h>
#include<math.h>

struct golden {
    long long int a;
    long long int b;
};

int main() {

    struct golden x, y;
    scanf("%lld %lld", &x.a, &x.b);
    scanf("%lld %lld", &y.a, &y.b);

    double k = (1 + sqrt(5))/2;
    // k *= 1000000;
    double p = x.a + x.b * k;
    double q = y.a + y.b * k;
    // long long int p = x.a + x.b * k;
    // long long int q = y.a + y.b * k;
    p *= 100000000;
    q *= 100000000;

    printf("%lf\n", p); //チェッカーの値確認用
    printf("%lf\n", q); //チェッカーの値確認用

    if(p > q) printf("%d\n",1);
    else if(p < q) printf("%d\n", -1);
    else printf("%d\n", 0);

    return 0;
}
