#include<stdio.h>
#include<stdlib.h>

#define MAXSTACK 513
char buf[MAXQUEUE];
typedef int elementtype;

struct stack {
    int top;
    elementtype elements[MAXQUEUE];
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

    if(p->top >= MAXQUEUE) {

        printf("Overflow\n");
        exit(1);

    } else {
        p->elements[p->top] = e;
    }
    return;
}

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    if (open == '<' && close == '>') return 1;
    return 0;
}


int main() {
    struct stack s;

    // スタックsの初期化
    initstack(&s);

    fgets(buf, sizeof(buf), stdin);

    // 改行文字を無視
    for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == '\n') {
            buf[i] = '\0';
            break;
        }
    }

    for(int i = 0; buf[i] != '\0'; i++) {

        if (buf[i] == '(' || buf[i] == '{' || buf[i] == '[' || buf[i] == '<') {
            // 開き括弧ならスタックにプッシュ
            push(&s, buf[i]);
        }
        else if (buf[i] == ')' || buf[i] == '}' || buf[i] == ']' || buf[i] == '>') {
            //閉じ括弧なら、対応する開きがストックのトップにあるか確認

            if (stackempty(&s) || !isMatchingPair(pop(&s), buf[i])) {
                printf("Bad\n");
                return 1;
            }
        }
    }

    // 全ての括弧が対応しているか確認
    if (s.top == -1) {
        printf("Good\n");
    } else {
        printf("Bad\n");
    }

    return 0;
}