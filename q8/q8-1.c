#include <stdio.h>
#include "/ced-home/staff/24jr3/include/jr3.h"
char rule;
struct point { int x, y; };

int compare_X(struct point p1, struct point p2) {
    if (p1.x != p2.x)
        return (p1.x > p2.x) ? 1 : -1;
    return (p1.y > p2.y) ? 1 : (p1.y < p2.y) ? -1 : 0;
}

int compare_Y(struct point p1, struct point p2) {
    if (p1.y != p2.y)
        return (p1.y > p2.y) ? 1 : -1;
    return (p1.x > p2.x) ? 1 : (p1.x < p2.x) ? -1 : 0;
}

int compare_D(struct point p1, struct point p2) {
    int d1 = p1.x * p1.x + p1.y * p1.y;
    int d2 = p2.x * p2.x + p2.y * p2.y;
    if (d1 != d2)
        return (d1 > d2) ? 1 : -1;
    return compare_X(p1, p2);
}

int compare(struct point p1, struct point p2) {
    if(rule == 'X') {
        return compare_X(p1, p2);
    }
    else if(rule == 'Y') {
        return compare_Y(p1, p2);
    }
    else if(rule == 'D') {
        return compare_D(p1, p2);
    }
}

void swap(struct point *p1, struct point *p2) {
    struct point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(struct point a[], int m ,int n) {
    // (1)
    struct point pivot = a[m];
    int l = m+1;
    int r = n;

    // (2)
    while(l <= r){
        while(l <= n && compare(pivot, a[l]) > 0) l++;
        while(m < r && compare(a[r], pivot) > 0) r--;
        if(l < r) {
            swap(&a[l], &a[r]);
        }
        else {
            break;
        }
    }

    // (3)
    a[m] = a[r];
    a[r] = pivot;

    // (4)
    return r;
}

int main() {
    char buf[128];
    struct point p, arr[128];
    int i = 0, n;

    if(scanf("%c ", &rule) == EOF) {
        fprintf(stderr, "No rule was specified. \n");
        return 1;
    }
    while(fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
        sscanf(buf, "%d %d", &p.x, &p.y);
        arr[i] = p;
        i++;
    }
    n = i;
    printf("%d\n", partition(arr, 0, n-1));
    for(i = 0; i < n; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);
    return 0;
}

