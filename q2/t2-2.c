#include <stdio.h>

int combination(int n, int k, int conv[1000][1000]){

    if(k == 0 || k == n) return 1;

    if(conv[n][k] != -1) return conv[n][k];

    conv[n][k] = (combination(n-1, k, conv) + combination(n-1, k-1, conv)) %2719;

    return conv[n][k];
}

int main() {

    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int conv[1000][1000]; // n, k
    for(int i = 0; i<= n; i++) {
        for(int j = 0; j <= k; j++) {

            conv[i][j] = -1;
        }
    }

    int result = combination(n, k, conv);

    printf("%d", result);

    return 0;
}