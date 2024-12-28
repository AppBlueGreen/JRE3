#include<stdio.h>
#include<stdlib.h>
#include "/ced-home/staff/24jr3/include/jr3.h"

char buf[128]; // get_treeで用いるグローバル変数

typedef char datatype;
struct node {datatype data; struct node *left, *right; };

struct node* get_tree() {
    struct node *t;
    if(fgets(buf,sizeof(buf),stdin)==NULL || buf[0]=='.')
        return NULL;
    else {
        /* 先頭が. 以外なら、節点のためのメモリを確保 */
        t = (struct node*)malloc(sizeof(struct node));
        sscanf(buf,"%c ",&t->data); /* buf から数値として読み込み、メンバ data に保存 */
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

void print_preorder(struct node *t) {
    if(t == NULL) return; // 葉の場合
    // 節点の場合
    printf("%c", t->data);
    print_preorder(t->left);
    print_preorder(t->right);
    return;
}

void print_inorder(struct node *t) {
    if(t == NULL) return; // 葉の場合
    // 節点の場合
    print_inorder(t->left);
    printf("%c", t->data);
    print_inorder(t->right);
    return;
}

void print_postorder(struct node *t) {
    if(t == NULL) return; // 葉の場合
    // 節点の場合
    print_postorder(t->left);
    print_postorder(t->right);
    printf("%c", t->data);
    return;
}

int main() {
    struct node *t = get_tree();
    print_preorder(t);  printf("\n");
    print_inorder(t);   printf("\n");
    print_postorder(t); printf("\n");
    return 0;
}