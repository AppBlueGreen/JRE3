#include <stdio.h>

#define arraySize 100000

int main(void) {

  int n;
  scanf("%d", &n); // 標準入力から与えられた整数n

  int fib[arraySize] = {0, 1};

  for(int i= 2; i <= n; i++) {

      fib[i] = (fib[i-1] + fib[i-2] )% 2719;
  }

  printf("%d",fib[n]);
  
  return 0;
}
