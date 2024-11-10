#include <stdio.h>

int is_prime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int a, b;

    do {
        printf("请输入范围 (a, b)，要求 10 <= a <= b <= 1000: \n");
        scanf("%d %d", &a, &b);
        if (a < 10 || b > 1000 || a > b) {
            printf("输入数据无效，请重新输入。\n");
        }
    } while (a < 10 || b > 1000 || a > b);

    printf("范围内的质数为：\n");

    int count = 0;
    for (int x = a; x <= b; x++) {
        if (is_prime(x)) {
            printf("%d\t", x);
            count++;
            if (count % 5 == 0) {
                printf("\n");
            }
        }
    }

    if (count % 5 != 0) {
        printf("\n");
    }

    return 0;
}