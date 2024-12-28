#include<stdio.h>
#include<stdlib.h>
#include "/ced-home/staff/24jr3/include/jr3.h"

char buf[128]; // get_treeで用いるグローバル変数

typedef int datatype;
struct node {datatype data; struct node *left, *right; };

struct node* get_tree() {
    struct node *t;
    if(fgets(buf,sizeof(buf),stdin)==NULL || buf[0]=='.')
        return NULL;
    else {
        /* 先頭が. 以外なら、節点のためのメモリを確保 */
        t = (struct node*)malloc(sizeof(struct node));
        sscanf(buf,"%d ",&t->data); /* buf から数値として読み込み、メンバ data に保存 */
        t->left = get_tree(); /* 以降の入力で、左の子の節点から下の木を生成 */
        t->right = get_tree(); /* 左の木が生成できたら、右の子の節点から下の木を生成 */
        return t;
    }
}

void print_tree(struct node *t) {
    if(t == NULL) { // 葉
        printf("-");
        return;
    }
    //　節点
    printf("%d(", t->data);
    print_tree(t->left);
    printf(",");
    print_tree(t->right);
    printf(")");
    return;
}

int size(struct node *t) {
    if(t == NULL) return 0; //葉に到達した場合

    // 節点の場合
    return 1 + size(t->left) + size(t->right); // +1は自分自身の節点分
}

int height(struct node *t) {
    if(t == NULL) return 0; // 葉に到達した場合

    // 節点の場合
    int leftHeight = 1 + height(t->left);
    int rightHeight = 1 + height(t->right);

    if(leftHeight >= rightHeight) return leftHeight;
    else return rightHeight;

}

int sum(struct node *t) {
    if(t == NULL) return 0; // 葉に到達した場合
    // 節点の場合
    return t->data + sum(t->left) + sum(t->right);
}

int main() {
    struct node *t = get_tree();
    printf("%d\n", size(t));
    printf("%d\n", height(t));
    printf("%d\n", sum(t));
    return 0;
}