#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "/ced-home/staff/24jr3/include/jr3.h"

#define SIZE 101
struct student {int id; char name[32]; int score;};
struct node {struct student data; struct node *next;};

int hash (char *s) {
    int arrayNumber = strlen(s);
    int hash = 0;
    for (int i = 0; i < arrayNumber; i++) {
        hash = (hash * 128 + s[i]) % SIZE;
    }
    return hash;
}

void set_data(struct node *table[], struct student st) {
    int setNumber = hash(st.name);
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = st;
    n->next = NULL;

    if(table[setNumber] == NULL) { //データが存在しない場合
        table[setNumber] = n;
    } else { // すでにデータが存在する場合
        struct node *p = table[setNumber];
        n->next = p;
        table[setNumber] = n;
    }
}

int main () {
    int i;
    char buf[128];
    struct student st;
    struct node *table[SIZE], *p;
    // ハッシュ表の配列の各要素をNULLで初期化
    for (i = 0; i < SIZE; i++) table[i] = NULL;
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        sscanf(buf,"%d,%[^,],%d", &st.id, st.name, &st.score);
        set_data(table, st); //ハッシュ表にstを登録
    }
    for (i = 0; i < SIZE; i++) {
        p = table[i];
        while(p != NULL) {
            st = p->data;
            printf("(%d)%d,%s,%d\n", i, st.id, st.name, st.score);
            p = p->next;
        }
    }
    return 0;
}