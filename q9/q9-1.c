#include<stdio.h>
#include<stdlib.h>
#include "/ced-home/staff/24jr3/include/jr3.h"

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

int is_heap(struct point a[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && compare(a[left], a[i]) > 0) return 0;
        if (right < n && compare(a[right], a[i]) > 0) return 0;
    }
    return 1;
}

int main() {
    char buf[128];
    struct point p, arr[128];
    int i = 0, n;
    if (scanf("%c ", &rule) == EOF) {
        fprintf(stderr,"No rule was specified.\n");
        return 1;
    }
    while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
        sscanf(buf, "%d %d", &p.x, &p.y);
        arr[i] = p;
        i++;
    }
    n = i;
    if (is_heap(arr, n)) printf("Yes.\n");
    else printf("No.\n");
    return 0;
}