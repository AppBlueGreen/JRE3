int main() {
    int d;
    char c;
    list l1 = (list)malloc(sizeof(struct node)); 
    list l2 = (list)malloc(sizeof(struct node)); 
    list l3 = (list)malloc(sizeof(struct node)); 

    l1->next = NULL;
    l2->next = NULL;
    l3->next = NULL;

    // 入力を1桁ずつリストに追加
    while ((c = getchar()) != '\n' && c != EOF) {
        if (c >= '0' && c <= '9') {
            d = (int)c - '0';
            insert(l1, d);
        }
    }

    while ((c = getchar()) != '\n' && c != EOF) {
        if (c >= '0' && c <= '9') {
            d = (int)c - '0';
            insert(l2, d);
        }
    }

    // リストを逆順にして計算しやすくする
    reverse(l1);
    reverse(l2);

    // 掛け算の実行
    multi(l1, l2, l3);

    // 結果のリストを逆順にして表示
    reverse(l3);

    // 結果の出力（先頭の0をスキップ）
    l3 = l3->next;
    while (l3 != NULL && l3->element == 0) {
        l3 = l3->next;  // 先頭の0をスキップ
    }

    // 出力
    if (l3 == NULL) {
        printf("0");  // 結果が0の場合
    } else {
        while (l3 != NULL) {
            printf("%d", l3->element);
            l3 = l3->next;
        }
    }
    printf("\n");

    free(l1);
    free(l2);
    free(l3);

    return 0;
}
