#include <stdio.h>

int main() {

  int array[10];
  int minindex, temp;
  
  for(int i = 0; i < 10; i++) {

    scanf("%d", &array[i]);
  }

  
  for(int i = 0; i < 10; i++){

    minindex = i;

    for(int j = i+1; j< 10; j++) {

      if(array[j] < array[minindex]) {minindex = j;}
    }

    temp = array[minindex];
    array[minindex] = array[i];
    array[i]  = temp;
    
  }

  printf("%d", array[1]);
  
  return 0;
}
