#include<stdio.h>
#include "/ced-home/staff/24jr3/include/jr3.h"

typedef int elementtype;
struct node {
    elementtype element;
    struct node* next;
};
typedef struct node* list;

void init_list(list l) {
    list l = (list)malloc(sizeof(struct node));
    l->next = NULL;
}

void insert(list l, int e) {
    list n = (list)malloc(sizeof(struct node));
    n->element = e;
    n->next = l->next;
    l->next = n;
}

int get_length(list l) {

    int i;
    l = l->next;

    for(i = 0; l != NULL; i++)
        l = l->next;

    return i;
}

void add(list l1, list l2, list l3) {

    l1 = l1->next;
    l2 = l2->next;
    l3 = l3->next;
    int carry = 0;

    for(int i = 0; i < get_length(l3); i++) {
        int sum = l1->element + l2->element + carry;
        l3->element = sum % 10;
        carry = sum / 10;
    }
}

int main() {
    int d;
    char c;
    //リストlの初期化
    list l1, l2, l3;
    init_list(l1);
    init_list(l2);
    init_list(l3);

    //l1, l2に各位の桁を入れ込む
    while((c = getchar()) != '\n') { //読み込んだ数値をcに入れて、改行文字まで以下を繰り返す

        d = (int)c - '0';

        //ここで読み込んだ数字dを処理(リストに挿入するなど)
        insert(l1,d);
    }
    while((c = getchar()) != '\n') { //読み込んだ数値をcに入れて、改行文字まで以下を繰り返す

        d = (int)c - '0';

        //ここで読み込んだ数字dを処理(リストに挿入するなど)
        insert(l2,d);
    }

    //l1, l2の長さを取得. それを元に代入先のl3の長さを決定
    int len_1 = get_length(l1);
    int len_2 = get_length(l2);
    int len_3 = len_1 > len_2 ? len_1 : len_2;
    for(int i = 0; i < len_3; i++)
        insert(l3, 0);

    add(l1, l2, l3);

    // 末尾から辿って０でない桁を探す
    list last_l3 = l3->next; // l3の末尾記録用
    list prev_l3 = l3; // last_l3のひとつ前
    for(int i = 0; i < len_3; i++) {
        last_l3 = last_l3->next;
        prev_l3 = prev_l3->next;
    }
}