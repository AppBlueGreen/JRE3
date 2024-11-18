#include <stdio.h>
#include "/ced-home/staff/24jr3/include/jr3.h"

struct point { int x, y; };

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

int max_index_by(struct point a[], int n, char c) {

    int max_number = 0;
    struct point max = a[0];

    for(int i = 0; i < n; i++) {

        if(compare_by(a[i], max, c) == 1 || compare_by(a[i], max, c) == 0) {
            max_number = i;
            max = a[i];
        }
    }
    return max_number;
}

int main() {
    char c, buf[128];
    struct point p, arr[128];
    int i = 0;
    scanf("%c ",&c);
    while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
        sscanf(buf,"%d %d", &p.x, &p.y);
        arr[i] = p;
        i++;
    }
    printf("%d\n", max_index_by(arr, i, c));
    return 0;
}
