#include<stdio.h>
#include<stdlib.h>
#include "/ced-home/staff/24jr3/include/jr3.h"

struct point {int x, y;};

void bucket_sort(struct point a[], int n) {

    // (1)
    int c[100] = {};
    struct point b[n];
    // (2), (4)
    for(int i = 0; i < n; i++) {
        c[a[i].x]++;
        b[i] = a[i];
    }
    // (3)
    for(int i = 1; i < 100; i++)
        c[i] += c[i-1]; 
    // (5)
    for(int i = n-1; i >= 0; i--) {
        // (i)
        c[b[i].x]--;
        // (ii)
        a[c[b[i].x]] = b[i];
    }
}

int main() {
    char buf[128];
    struct point p, arr[128];
    int i = 0, n;
    while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
        sscanf(buf, "%d %d", &p.x, &p.y);
        arr[i] = p;
        i++;
    }
    n = i;
    bucket_sort(arr, n);
    for(i = 0; i < n; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);
    return 0;
}