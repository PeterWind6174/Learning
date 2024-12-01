#include <stdio.h>

// 函数定义：打印等腰三角形
void DrawTriangle(int n, char c) {
    for (int i = 1; i <= n; i++) {
        // 打印空格，使等腰三角形居中
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // 打印字符，构成等腰三角形的行
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("%c", c);
        }
        // 换行，打印下一行
        printf("\n");
    }
}

int main() {
    // 打印 5 行的 '*' 等腰三角形
    DrawTriangle(5, '*');
    // 空行分隔
    printf("\n");
    // 打印 10 行的 '#' 等腰三角形
    DrawTriangle(10, '#');
    return 0;
}