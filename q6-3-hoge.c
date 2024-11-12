#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;
struct node {
    elementtype element;
    struct node* next;
};
typedef struct node* list;

void insert(list l, int e) {
    list n = (list)malloc(sizeof(struct node));
    n->element = e;
    n->next = NULL;

    while (l->next != NULL)
        l = l->next;
    l->next = n;
}

list add(list l1, list l2) {
    list result = (list)malloc(sizeof(struct node));
    result->next = NULL;
    list tail = result;

    int carry = 0;
    l1 = l1->next; // skip dummy node
    l2 = l2->next; // skip dummy node
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

        list n = (list)malloc(sizeof(struct node));
        n->element = sum % 10;
        n->next = NULL;
        tail->next = n;
        tail = n;

        carry = sum / 10;
    }
    return result;
}

void print_list(list l) {
    l = l->next; // skip dummy node
    while (l != NULL) {
        printf("%d", l->element);
        l = l->next;
    }
    printf("\n");
}

int main() {
    int d;
    char c;
    list l1 = (list)malloc(sizeof(struct node)); l1->next = NULL;
    list l2 = (list)malloc(sizeof(struct node)); l2->next = NULL;

    while ((c = getchar()) != '\n') {
        d = (int)c - '0';
        insert(l1, d);
    }

    while ((c = getchar()) != '\n') {
        d = (int)c - '0';
        insert(l2, d);
    }

    list l3 = add(l1, l2);
    print_list(l3);

    return 0;
}
