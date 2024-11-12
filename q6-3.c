#include<stdio.h>
#include "/ced-home/staff/24jr3/include/jr3.h"

typedef int elementtype;
struct node {
    elementtype element;
    struct node* next;
};
typedef struct node* list;

int get_length(list l) {
    int i = 0;
    l = l->next;

    while(l != NULL) {
        l = l->next;
        i++;
    }

    return i;
}

void insert(list l, int e) {

    list n = (list)malloc(sizeof(struct node));
    n->element = e;
    n->next = NULL;

    while(l->next != NULL)
        l = l->next;
    l->next = n;
}

// l1とl2の各要素の結果をl3に格納
void add(list l1, list l2, list l3) {

    l1 = l1->next;
    l2 = l2->next;
    l3 = l3->next;
    int sum;

    int len_1 = get_length(l1);
    int len_2 = get_length(l2);
    int max_len = len_1 > len_2 ? len_1 : len_2;


    int carry = 0;
    for(int i = 0; i < max_len || carry > 0; i++) {

        if(l1 == NULL) {

            insert(l3,0);
            sum = l2->element + carry;
            l3->element = sum % 10;
            carry = sum / 10;

            l2 = l2->next;
            l3 = l3->next;

        }
        else if(l2 == NULL) {
            insert(l3,0);
            sum = l1->element + carry;
            l3->element = sum % 10;
            carry = sum / 10;

            l1 = l1->next;
            l3 = l3->next;
        }
        else if(l1 == NULL && l2 == NULL) {
            insert(l3,0);

            l3->element = carry;
            l3 = l3->next;
        }
        else {
            insert(l3,0);
            sum = l1->element + l2->element + carry;
            l3->element = sum % 10;
            carry = sum / 10;

            l1 = l1->next;
            l2 = l2->next;
            l3 = l3->next;
        }
    }
}

//引数としているノードの一つ先のノードを削除
void delete_next(list l) {
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
    //リストlの初期化
    list l1 = (list)malloc(sizeof(struct node)); l1->next = NULL;
    list l2 = (list)malloc(sizeof(struct node)); l2->next = NULL;
    list l3 = (list)malloc(sizeof(struct node)); l3->next = NULL;

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

    //逆順にするメソッド
    reverse(l1);
    reverse(l2);

    add(l1, l2, l3);

    // 結果の出力
    l3 = l3->next;
    while(l3 != NULL) {
        printf("%d", l3->element);
        l3 = l3->next;
    }
    printf("\n");
    return 0;
}