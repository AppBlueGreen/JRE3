#include <stdio.h>
#include "/ced-home/staff/24jr3/include/jr3.h"

int max_index(int a[], int n) {

    int max_number = 0;
    int max = a[0];

    for(int i = 0; i < n; i++) {
        if(max <= a[i]) {
            max_number = i;
            max = a[i];
        }
    }
    return max_number;
}

int main() {
    char buf[128];
    int arr[128], i = 0;
    while(fgets(buf, sizeof(buf), stdin) != NULL && i < 128)
        sscanf(buf, "%d", &arr[i++]);
    printf("%d\n", max_index(arr, i));
    return 0;
}