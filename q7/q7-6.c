#include <stdio.h>
#include "/ced-home/staff/24jr3/include/jr3.h"

struct point { int x, y; };

int count = 0;

int compare_X(struct point p1, struct point p2) {
    if(p1.x > p2.x) {
        return 1;
    }
    else if(p1.x == p2.x) {
        if(p1.y > p2.y) {
            return 1;
        }
        else if(p1.y == p2.y) {
            return 0;
        }
        else if(p1.y < p2.y) {
            return -1;
        }
    }
    else if(p1.x < p2.x) {
        return -1;
    }
}
int compare_Y(struct point p1, struct point p2) {

    if(p1.y > p2.y) {
        return 1;
    }
    else if(p1.y == p2.y) {
        if(p1.x > p2.x) {
            return 1;
        }
        else if(p1.x == p2.x) {
            return 0;
        }
        else if(p1.x < p2.x) {
            return -1;
        }
    }
    else if(p1.y < p2.y) {
        return -1;
    }
}
int compare_D(struct point p1, struct point p2) {

    if((p1.x * p1.x + p1.y * p1.y) > (p2.x * p2.x + p2.y * p2.y)) {
        return 1;
    }
    else if((p1.x * p1.x + p1.y * p1.y) == (p2.x * p2.x + p2.y * p2.y)) {
        return compare_X(p1, p2);
    }
    else if((p1.x * p1.x + p1.y * p1.y) < (p2.x * p2.x + p2.y * p2.y)) {
        return -1;
    }
}

int compare_by(struct point p1, struct point p2, char c) {

    count++;

    if(c == 'X') {
        return compare_X(p1, p2);
    }
    else if(c == 'Y') {
        return compare_Y(p1, p2);
    }
    else if(c == 'D') {
        return compare_D(p1, p2);
    }
}

void swap(struct point *p1, struct point *p2) {
    struct point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void bubble_sort(struct point a[], int n, char c) {
    for(int k = n-2; k >= 0; k--) {

        for(int i = 0; i <= k; i++) {
            if(compare_by(a[i], a[i+1], c) == 1)  
                swap(&a[i], &a[i+1]);  
        }
    }

}

int main() {
    char c, buf[128];
    struct point p, arr[128];
    int i = 0, n;
    scanf("%c ",&c);
    while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
        sscanf(buf,"%d %d", &p.x, &p.y);
        arr[i] = p;
        i++;
    }
    n = i;
    bubble_sort(arr, n, c);
    printf("%d\n", count);
    for(i = 0; i < n; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);
    return 0;
}