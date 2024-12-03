#include <stdio.h>
#include "/ced-home/staff/24jr3/include/jr3.h"

int count = 0;
char rule;

struct point {int x, y;};

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
    count++;
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

void merge(struct point a[], int m, int n, int h) {
    int i = m, j = h+1, k = 0;
    struct point result[n-m+1];

    while(i <= h && j <= n) {

        if(compare(a[i], a[j]) > 0) { // a[j] < a[i]
            result[k++] = a[j++];
        }
        else {                        // a[i] <= a[j]
            result[k++] = a[i++];
        }
    }
    while( i <= h) result[k++] = a[i++];
    while( j <= n) result[k++] = a[j++];

    for(k = 0; k < n-m+1; k++)
        a[m+k] = result[k];
}

void merge_sort(struct point a[], int m, int n) {
    if(m < n) {
        int h = (m+n) / 2;
        merge_sort(a, m, h);
        merge_sort(a, h+1, n);
        merge(a, m, n, h);
    }
}

int main() {
    char buf[128];
    struct point p, arr[128];
    int i = 0, n;

    if(scanf("%c ", &rule) == EOF) {
        fprintf(stderr, "No rule and/or subscript was specified.\n");
        return 1;
    }
    while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
        sscanf(buf, "%d %d", &p.x, &p.y);
        arr[i] = p;
        i++;
    }
    n = i;
    merge_sort(arr, 0, n-1);
    printf("%d\n", count);
    for(i = 0; i < n; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);
    return 0;
}