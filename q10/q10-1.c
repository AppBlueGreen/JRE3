#include<stdio.h>
#include "/ced-home/staff/24jr3/include/jr3.h"

struct student {int id; char name[32]; int score;};

int main() {
    int i = 0, n, v;
    char buf[128], c;
    struct student st[1024];
    while(fgets(buf, sizeof(buf), stdin) != NULL && i < 1024) {
        sscanf(buf, "%d%c", &v, &c);
        if(c == ',') {
            st[i].id = v;
            sscanf(buf,"%*d,%[^,],%d", st[i].name, &st[i].score);
            i++;
        }
    }
    n = i;
    i = 0;
    while(1) {
        if(st[i].score == v || i == n)
            break;
        i++;
    }

    if(i == n) {
        printf("Not found.\n");
        return 0;
    }
    printf("%d,%s\n", st[i].id, st[i].name);
    return 0;
}