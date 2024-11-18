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

        if(p->front == MAXQUEUE) {
            printf("Sorry\n");
            exit(1);
        }
        return p->elements[p->front++];
    }
}

//構造体queueのアドレスを受け取り、そのキューにeを入れる関数。
void putq(struct queue *p, elementtype e) {

    if(p->rear == MAXQUEUE) {
        printf("Sorry\n");
        exit(1);

    } else {
        p->elements[p->rear++] = e;
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
        for(int j = q.front; j < q.rear; j++) {
            printf("[%d]", q.elements[j]);
        }
        printf("\n");
    }

    return 0;
}