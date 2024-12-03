#include<stdio.h>
#include<stdlib.h>
#include "/ced-home/staff/24jr3/include/jr3.h"

int count = 0;
char rule;

struct point {int x, y; };
typedef struct point elementtype;

struct node {elementtype element; struct node *next; };
typedef struct node* list;

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

void split(list l1, list l2) {
    list p1 = l1;   list p2 = l1;
    while(p2 != NULL && p2->next != NULL) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    l2->next = p1->next;
    p1->next = NULL;
}

void merge(list l1, list l2) {

    list dummy = (list)malloc(sizeof(struct node));
    list tail = dummy;

    list p1 = l1->next; 
    list p2 = l2->next;

    while (p1 != NULL && p2 != NULL) {
        if (compare(p1->element, p2->element) <= 0) {
            tail->next = p1;
            p1 = p1->next;
        } else {
            tail->next = p2;
            p2 = p2->next;
        }
        tail = tail->next;
    }

    tail->next = (p1 != NULL) ? p1 : p2;

    l1->next = dummy->next;
    free(dummy);
}


void merge_sort(list l) {

    if(l == NULL || l->next == NULL || l->next->next == NULL) return;

    list l2 = (list)malloc(sizeof(struct node));
    l2->next = NULL;
    split(l, l2);
    merge_sort(l);
    merge_sort(l2);
    merge(l, l2);

    free(l2);
}

int main() {
    char buf[128];
    struct point p;
    list l, last;
    if(scanf("%c ", &rule) ==EOF) {
        fprintf(stderr, "No rule was specified.\n");
        return 1;
    }

    last = l = (list)malloc(sizeof(struct node));
    while(fgets(buf, sizeof(buf), stdin) != NULL) {
        sscanf(buf, "%d %d", &p.x, &p.y);
        last = last->next = (list)malloc(sizeof(struct node));
        last->element = p;
    }
    last->next = NULL;

    merge_sort(l);

    printf("%d\n", count);
    while((l = l->next) != NULL) {
        p = l->element;
        printf("%d %d\n", p.x, p.y);
    }
    return 0;
}