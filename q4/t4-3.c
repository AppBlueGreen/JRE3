#include<stdio.h>
#include<stdlib.h>

#define MAXSTACK 128
char buf[128];
typedef int elementtype;

struct stack {
    int top;
    elementtype elements[MAXSTACK];
};

// 構造体stack のアドレスを受け取り、そのスタックを空にする関数
void initstack(struct stack *p) {
    p->top = -1;
    return;
}


//　構造体stack のアドレスを受け取り、そのスタックが空なら1、空でなければ0 を返す関数
int stackempty(struct stack *p) {
    return p->top < 0;
}


// 構造体stack のアドレスを受け取り、そのスタックから要素をポップし、その要素を返す関数
elementtype pop(struct stack *p) {
    
    elementtype val;

    if(stackempty(p)) {

        printf("Underflow\n");
        exit(1);

    } else {

        val = p->elements[p->top];
        p->top--;
        return val;
    }
}


// 構造体stack のアドレスを受け取り、そのスタックにe をプッシュする関数
void push(struct stack *p, elementtype e) {

    p->top++;

    if(p->top >= MAXSTACK) {

        printf("Overflow\n");
        exit(1);

    } else {
        p->elements[p->top] = e;
    }
    return;
}


int main() {
    struct stack s;
    int i;

    // スタックsの初期化
    initstack(&s);

    while(fgets(buf, sizeof(buf), stdin) != NULL) {

        if(buf[0] == 'p') { // スタックsからのポップ操作

            elementtype val = pop(&s);

        } else { //スタックsへのiのプッシュ操作

            sscanf(buf, "%d", &i);
            push(&s, i);
        }

        //　スタックsの中身を指定された形式で出力
        for(int j = 0; j <= s.top; j++) {
            printf("[%d]", s.elements[j]);
        }
        printf("\n");
    }
}