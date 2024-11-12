#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;
struct node {
    elementtype element;
    struct node* next;
};
typedef struct node* list;

int get_length(list l) {
    int i = 0; // 変数iの初期化が必要
    l = l->next;
    while(l != NULL) {
        l = l->next;
        i++;
    }
    return i;
}

void insert(list l, int e) {
    list n = (list)malloc(sizeof(struct node));
    if (n == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    n->element = e;
    n->next = NULL;

    while(l->next != NULL) {
        l = l->next;
    }
    l->next = n;
}

void add(list l1, list l2, list l3) {
    l1 = l1->next;
    l2 = l2->next;

    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry > 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->element;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->element;
            l2 = l2->next;
        }
        insert(l3, sum % 10);
        carry = sum / 10;
    }
}

void delete_next(list l) {
    if (l->next == NULL) return;
    list temp = l->next;
    l->next = l->next->next;
    free(temp);
}

void reverse(list l) {
    list prev = NULL, current = l->next, next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    l->next = prev;
}

int main() {
    int d;
    char c;
    list l1 = (list)malloc(sizeof(struct node)); 
    list l2 = (list)malloc(sizeof(struct node)); 
    list l3 = (list)malloc(sizeof(struct node)); 

    if (!l1 || !l2 || !l3) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    l1->next = NULL;
    l2->next = NULL;
    l3->next = NULL;

    while((c = getchar()) != '\n' && c != EOF) {
        if (c >= '0' && c <= '9') {
            d = (int)c - '0';
            insert(l1, d);
        }
    }

    while((c = getchar()) != '\n' && c != EOF) {
        if (c >= '0' && c <= '9') {
            d = (int)c - '0';
            insert(l2, d);
        }
    }

    reverse(l1);
    reverse(l2);

    add(l1, l2, l3);

    reverse(l3);

    l3 = l3->next;
    while(l3 != NULL) {
        printf("%d", l3->element);
        l3 = l3->next;
    }
    printf("\n");

    free(l1);
    free(l2);
    free(l3);

    return 0;
}