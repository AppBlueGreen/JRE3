#include<stdio.h>
#define N 11
char buf[N+2];
char canvas[N][N];

struct coord{int x,y;};

void mapping(char canvas[N][N]) {

    canvas[N/2][N/2] = 'o';

    int flag = 1;

    while(flag) {

        flag = 0;

        for(int i = 0; i < N; i++) {

            for(int j = 0; j < N; j++) {

                if(canvas[i][j] == 'o') {

                    if(i-1 >= 0 && canvas[i-1][j] == ' ') {
                        canvas[i-1][j] = 'o'; flag = 1;
                    }
                    if(i+1 < N && canvas[i+1][j] == ' ') {
                        canvas[i+1][j] = 'o'; flag = 1;
                    }
                    if(j-1 >= 0 && canvas[i][j-1] == ' ') {
                        canvas[i][j-1] = 'o'; flag = 1;
                    }
                    if(j+1 < N && canvas[i][j+1] == ' ') {
                        canvas[i][j+1] = 'o'; flag = 1;
                    }
                }
            }
        }
    }
}

int main() {
    int i,j;
    i = 0;

    // 入力を1行ずつ読み込んでmapへ格納
    while(fgets(buf, sizeof(buf), stdin) != NULL) {

        for(j = 0; j < N; ++j)
            canvas[i][j] = buf[j];
        ++i;
    }

    // ここを埋める
    mapping(canvas);

    // canvasの出力
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j )
            printf("%c",canvas[i][j]);
        printf("\n");
    }

    return 0;
}