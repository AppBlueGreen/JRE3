#include <stdio.h>

void gcd(int* n, int* m, int* hoge) {

    if(*n % *m == 0) {

        *hoge = *m;

    }else {

      int temp = *n % *m;

      gcd(m, &temp, hoge);
    }
}

int main() {

  int n, m;

  int hoge = 1;
  
  scanf("%d", &n);
  scanf("%d", &m);

  gcd(&n, &m, &hoge);
    
  int lcm = n * m / hoge;
  printf("%d", lcm);
  return 0;
}