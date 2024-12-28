#include <stdio.h>
#include <stdlib.h>
#include "/ced-home/staff/24jr3/include/jr3.h"

char buf[128]; /* 関数 get_tree で用いるグローバル変数 */

struct student { int id; char name[32]; int score; };
typedef struct student datatype; /* ← 格納するデータは構造体 student */
struct node { datatype data; struct node *left, *right; };

/* 葉を含む行きがけ順で表現された文字列を二分木に変換 */
struct node* get_tree() {
    struct node *t;
    if (fgets(buf, sizeof(buf), stdin) == NULL || buf[0] =='.')
        return NULL;
    else {
        t = (struct node*)malloc(sizeof(struct node));
        sscanf(buf,"%d,%[^,],%d", &t->data.id, t->data.name, &t->data.score);
        t->left = get_tree();
        t->right = get_tree();
        return t;
    }
}

void find_info(struct node *t, int id) {

    if(t == NULL) {
        printf("Not found.\n");
        return; // 葉まで到達した場合
    }

    // 節点の場合
    if(id == t->data.id) { // IDが一致した場合

        printf("%s,%d\n",t->data.name,t->data.score);
        return;

    } else if ( id < t->data.id) {
        find_info(t->left,id);
        
    } else if (id > t->data.id) {

        find_info(t->right,id);
    }
}

struct node* bst_insert(struct node *t, struct student d) {
    struct node *result = t;
    if(t == NULL) { //　葉まで到達した場合
        t = (struct node*)malloc(sizeof(struct node));
        t->data = d;
        t->left = t->right = NULL;
        return t;
    }

    // 節点の場合
    if ( d.id < t->data.id) t->left = bst_insert(t->left,d);
    else                    t->right = bst_insert(t->right,d);
    
    return result;
}

void print_bst(struct node *t) {
    if(t == NULL) { // 葉まで到達した場合
        printf(".\n");
        return;
    }
    printf("%d,%s,%d\n",t->data.id,t->data.name,t->data.score);
    print_bst(t->left);
    print_bst(t->right);
}

int main(void) {
    struct student d;
    struct node *t = get_tree();
    if (scanf("%d,%[^,],%d ", &d.id, d.name, &d.score) == EOF) {
        printf("No information about the student is given.\n");
        return 1;
    }
    t = bst_insert(t, d);
    print_bst(t);
    return 0;
}