#include <stdio.h>
#include <stdlib.h>
#include "/ced-home/staff/24jr3/include/jr3.h"

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

    while (l->next != NULL) {
        l = l->next;
    }
    l->next = n;
}

void multi(list l1, list l2, list l3) {
    list l1_head = l1->next;
    l2 = l2->next;
    list l3_head = l3;

    for (int i = 0; l2 != NULL; i++) {
        int carry = 0;
        l1 = l1_head;
        l3 = l3_head;

        // シフト位置を進める(i回ずらす)
        for (int k = 0; k < i; k++)
            l3 = l3->next;

        // 各桁の乗算
        while (l1 != NULL) {
            if (l3->next == NULL) {
                insert(l3, 0);
            }
            l3 = l3->next;
            int sum = l1->element * l2->element + l3->element + carry;
            l3->element = sum % 10;
            carry = sum / 10;
            l1 = l1->next;
        }

        // キャリーの処理
        while (carry > 0) {
            if (l3->next == NULL) {
                insert(l3, 0);
            }
            l3 = l3->next;
            int sum = l3->element + carry;
            l3->element = sum % 10;
            carry = sum / 10;
        }
        l2 = l2->next;
    }
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

void delete_next(list l) {
    if (l->next == NULL) return;
    list temp = l->next;
    l->next = l->next->next;
    free(temp);
}

int main() {
    int d;
    char c;
    list l1 = (list)malloc(sizeof(struct node)); 
    list l2 = (list)malloc(sizeof(struct node)); 
    list l3 = (list)malloc(sizeof(struct node)); 

    l1->next = NULL;
    l2->next = NULL;
    l3->next = NULL;

    while ((c = getchar()) != '\n' && c != EOF) {
        if (c >= '0' && c <= '9') {
            d = (int)c - '0';
            insert(l1, d);
        }
    }

    while ((c = getchar()) != '\n' && c != EOF) {
        if (c >= '0' && c <= '9') {
            d = (int)c - '0';
            insert(l2, d);
        }
    }

    reverse(l1);
    reverse(l2);

    multi(l1, l2, l3);

    reverse(l3);
    if(l3->next->element == 0) {
        while(l3->next->next != NULL)
            delete_next(l3);
    }

    // 結果の出力
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
