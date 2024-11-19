#include<stdio.h>
#include "/ced-home/staff/24jr3/include/jr3.h"

struct point {int x, y;};
struct point_loc{int loc; struct point p;};

int compare_X(struct point_loc p1, struct point_loc p2) {

    if(p1.p.x > p2.p.x) {
        return 1;
    }
    else if(p1.p.x == p2.p.x) {
        if(p1.loc > p2.loc) {
            return 1;
        }
        else {
            return -1;
        }
    }
    else if(p1.p.x < p2.p.x) {
        return -1;
    }
}
int compare_Y(struct point_loc p1, struct point_loc p2) {

    if(p1.p.y > p2.p.y) {
        return 1;
    }
    else if(p1.p.y == p2.p.y) {
        if(p1.loc > p2.loc) {
            return 1;
        }
        else {
            return -1;
        }
    }
    else if(p1.p.y < p2.p.y) {
        return -1;
    }
}
int compare_D(struct point_loc p1, struct point_loc p2) {

    if((p1.p.x * p1.p.x + p1.p.y * p1.p.y) > (p2.p.x * p2.p.x + p2.p.y * p2.p.y)) {
        return 1;
    }
    else if((p1.p.x * p1.p.x + p1.p.y * p1.p.y) == (p2.p.x * p2.p.x + p2.p.y * p2.p.y)) {
        if(p1.loc > p2.loc) {
            return 1;
        }
        else {
            return -1;
        }
    }
    else if((p1.p.x * p1.p.x + p1.p.y * p1.p.y) < (p2.p.x * p2.p.x + p2.p.y * p2.p.y)) {
        return -1;
    }
}

int compare_by(struct point_loc p1, struct point_loc p2, char c) {

    if(c == 'x') {
        return compare_X(p1, p2);
    }
    else if(c == 'y') {
        return compare_Y(p1, p2);
    }
    else if(c == 'd') {
        return compare_D(p1, p2);
    }
}

int max_index_by(struct point_loc a[], int n, char c) {

    int max_number = 0;
    struct point_loc max = a[0];

    for(int i = 0; i < n; i++) {

        if(compare_by(a[i], max, c) == 1 || compare_by(a[i], max, c) == 0) {
            max_number = i;
            max = a[i];
        }

    }
    return max_number;
}

void swap(struct point_loc *p1, struct point_loc *p2) {
    struct point_loc temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void selection_sort(struct point_loc a[], int n, char c) {
    for(int k = n; k >= 2; k--) {
        int i = max_index_by(a, k, c);
        swap(&a[i], &a[k-1]);
    }
}

int main() {
    char c, buf[128];
    struct point_loc q, arr[128];
    int i = 0, n;
    scanf("%c ",&c);
    while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
        sscanf(buf,"%d %d", &q.p.x, &q.p.y);
        arr[i] = q;
        arr[i].loc = i;
        i++;
    }
    n = i;
    selection_sort(arr, n, c);
    for(i = 0; i < n; i++)
        printf("%d %d\n", arr[i].p.x, arr[i].p.y);
    return 0;
}