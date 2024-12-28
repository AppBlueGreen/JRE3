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

void print_bst(struct node *t) {
    if(t == NULL) { // 葉まで到達した場合
        printf(".\n");
        return;
    }
    printf("%d,%s,%d\n",t->data.id,t->data.name,t->data.score);
    print_bst(t->left);
    print_bst(t->right);
}

struct node* bst_delete(struct node *t, int id) {

    if(t == NULL) { // 葉まで到達した場合
        printf("Not found.\n");
        return NULL;
    }

    // 節点の場合
    if(id == t->data.id) { // IDが一致した場合

        if(t->right == NULL) { // n の右の子が葉であるとき、n があったところにn の左の子がそのまま入る。
            struct node *temp = t->left;
            free(t);
            return temp;
        }
        else if (t->right->left == NULL) { //n の右の子の左の子が葉であるとき、n があったところにはn の右の子の節点が入り、その左の子としてn の左の子が、右の子として、n の右の子の右の子が入る。
            struct node *temp1 = t->right;
            struct node *temp2 = t->left;
            free(t);
            temp1->left = temp2;
            return temp1;
        }
        else {
            struct node *minNode = t->right;
            while(minNode->left != NULL) minNode = minNode->left;
            t->data = minNode->data;
            t->right = bst_delete(t->right, minNode->data.id);
        }

    } else if ( id < t->data.id) {
        t->left = bst_delete(t->left,id);     
    } else if (id > t->data.id) {
        t->right = bst_delete(t->right,id);
    }

    return t;
}

int main(void) {
    int id;
    struct node *t = get_tree();
    if (scanf("%d ",&id) == EOF) {
        printf("No information about the student is given.\n");
        return 1;
    }
    t = bst_delete(t, id);
    print_bst(t);
    return 0;
}