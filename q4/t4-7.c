#include<stdio.h>
#include<stdlib.h>

#define MAXQUEUE 128
char buf[128];
typedef int elementtype;

struct queue {
    int rear;
    int front;
    elementtype elements[MAXQUEUE];
};

//構造体queueのアドレスを受け取り、そのキューを空にする関数
void initqueue(struct queue *p){
    p->front = p->rear = 0;
}

//構造体queueのアドレスを受け取り、そのキューが空なら０、空でなければ１を返す関数
int queueempty(struct queue *p) {
    return p->front == p->rear;
}

//構造体queueのアドレスを受け取り、そのキュー空要素を取り出し、その要素を返す関数。
elementtype getq(struct queue *p) {
    if(queueempty(p)) {
        printf("Underflow\n");
        exit(1);

    } else {

        elementtype val = p->elements[p->front++];
        if(p->front >= MAXQUEUE) {
            p->front = 0;
        }
        return val;
    }
}

//構造体queueのアドレスを受け取り、そのキューにeを入れる関数。
void putq(struct queue *p, elementtype e) {

    p->elements[p->rear++] = e;

    if(p->rear >= MAXQUEUE) {
        p->rear = 0;
    } 
    if(queueempty(p)) {
        printf("Overflow\n");
        exit(1);

    }
}


int main() {
    struct queue q;
    int i;

    // キューsの初期化
    initqueue(&q);

    while(fgets(buf, sizeof(buf), stdin) != NULL) {

        if(buf[0] == 'g') { // キューqからのゲット操作

            getq(&q);

        } else { //キューqへのiのプット操作

            sscanf(buf, "%d", &i);
            putq(&q, i);
        }

        //　キューqの中身を指定された形式で出力
        for(int j = q.front; j != q.rear; j++) {
            printf("[%d]", q.elements[j]);
            if(j + 1 == MAXQUEUE) {
                j = -1;
            }
        }
        printf("\n");
    }
    return 0;
}