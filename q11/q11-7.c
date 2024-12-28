#include <stdio.h>
#include <stdlib.h>
#include "/ced-home/staff/24jr3/include/jr3.h"

char buf[128]; /* 関数 get_tree で用いるグローバル変数 */

struct student { int id; char name[32]; int score; };
typedef struct student datatype; /* ← 格納するデータは構造体 student */
struct node { datatype data; struct node *left, *right; };

void bst_insert(struct node *t, struct student d) {
    struct node *dummy = t->left;
    struct node *current = t->right; //根ノードから開始
    struct node *parent = t; //親ノードを追跡

    // 挿入位置を探索
    while (current != dummy) { 
        parent = current;
        if (d.id < current->data.id) current = current->left;
        else if (current->data.id < d.id) current = current->right;
        else return; //同じIDが存在する場合
    }

    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = d; new->left = new->right = dummy;

    if(d.id < parent->data.id) parent->left = new;
    else if(parent->data.id < d.id) parent->right = new;
    else parent->right = new;
}

// 葉がダミーになった二分探索技を出力する関数
void print_bst_dummy(struct node *t, struct node *dummy) {
    if(t == dummy) printf(".\n");
    else {
        printf("%d,%s,%d\n",t->data.id,t->data.name,t->data.score);
        print_bst_dummy(t->left,dummy);
        print_bst_dummy(t->right,dummy);
    }
    return;
}

// 葉がダミーになった頭付きの二分探索技を出力する関数
void print_bst(struct node *t) {
    print_bst_dummy(t->right, t->left);
    return;
}

int main() {
    char buf[128];
    struct student st;
    struct node *t = (struct node*)malloc(sizeof(struct node));
    struct node *dummy = (struct node*)malloc(sizeof(struct node));
    t->left = t->right = dummy->left = dummy->right = dummy;
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        /* st の指すメモリに入力された学生のデータを格納 */
        sscanf(buf,"%d,%[^,],%d", &st.id,st.name, &st.score);
        /* 二分探索木にそのデータを追加 */
        bst_insert(t, st);
    }
    print_bst(t);
    return 0;
}