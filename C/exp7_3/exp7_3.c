#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000  // 定义字符串最大长度

int main() {
    char str[MAX_LENGTH];
    int i = 0, j = 0;

    // 提示用户输入字符串
    printf("请输入一个字符串（可包含空格）：\n");
    fgets(str, sizeof(str), stdin);

    // 移除字符串末尾的换行符（如果存在）
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // 遍历字符串，去除空格
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';  // 添加字符串结束符

    // 输出处理后的字符串
    printf("去除空格后的字符串为：%s\n", str);

    return 0;
}