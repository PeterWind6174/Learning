#include <stdio.h>

int main()
{
    FILE *fp; // 文件指针
    char ch;  // 临时存储读取字符
    // 1. 以写方式打开（或新建）文件 f1.txt
    // 如果打开失败，则返回
    if ((fp = fopen("f1.txt", "w")) == NULL)
    {
        printf("无法打开文件 f1.txt 进行写操作！\n");
        return 1;
    }

    // 2. 提示用户从键盘输入字符，以 '#' 结束
    printf("请输入字符，以 '#' 结束输入：\n");
    while ((ch = getchar()) != '#')
    {
        // 将用户输入的字符写入到文件中（不包含 '#')
        fputc(ch, fp);
    }

    // 写完后关闭文件
    fclose(fp);

    // 3. 以读方式打开文件，准备将内容读回并显示
    if ((fp = fopen("f1.txt", "r")) == NULL)
    {
        printf("无法打开文件 f1.txt 进行读操作！\n");
        return 1;
    }

    // 4. 从文件读取内容，并在显示器上原样显示
    printf("\n文件中的内容为: \n");
    while ((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }

    // 读完后关闭文件
    fclose(fp);

    return 0;
}