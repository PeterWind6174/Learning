#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STU 40 // 班级最多 40 名学生

// 学生信息的结构体定义
struct Student
{
    char ID[20];   // 学号
    char name[30]; // 姓名
    int age;       // 年龄
    double score;  // 成绩
};

// 功能：将学生数组的信息以二进制方式写入到 Info.dat 文件
void CreateFile(struct Student *students, int count)
{
    // 以二进制写方式 (wb) 打开文件，如果不存在则创建，存在则覆盖
    FILE *fp = fopen("Info.dat", "wb");
    if (fp == NULL)
    {
        printf("打开文件 Info.dat 失败！\n");
        exit(1); // 程序非正常结束
    }

    // 将学生数组中的所有学生信息写入文件
    fwrite(students, sizeof(struct Student), count, fp);

    fclose(fp);
}

// 功能：从 Info.dat 文件中读取学生信息，并依次输出到显示器上
int ReadOut(struct Student *students)
{
    FILE *fp = fopen("Info.dat", "rb");
    if (fp == NULL)
    {
        printf("打开文件 Info.dat 失败，无法进行读操作！\n");
        return 0; // 读取人数为 0
    }

    //  - 从文件中以二进制方式读取 nmemb 个大小为 size 的数据到 ptr 指向的内存区域
    int count = 0; // 实际读取到的学生人数
    // 这里使用循环读取，也可以直接一次性读取所有，然后计算读取到的数量。
    while (fread(&students[count], sizeof(struct Student), 1, fp) == 1)
    {
        count++;
        if (count >= MAX_STU)
        {
            break; // 避免超过上限
        }
    }

    fclose(fp);

    // 依次输出到显示器上
    printf("\n=== 文件读取结果 ===\n");
    for (int i = 0; i < count; i++)
    {
        printf("学号: %s, 姓名: %s, 年龄: %d, 成绩: %.2f\n",
               students[i].ID,
               students[i].name,
               students[i].age,
               students[i].score);
    }

    return count;
}

// 功能：对学生记录按成绩从高到低排序并输出结果
void Sort(struct Student *students, int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (students[j].score < students[j + 1].score)
            {
                // 交换记录
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    // 输出排序后的结果
    printf("\n=== 按成绩从高到低排序后的结果 ===\n");
    for (int i = 0; i < count; i++)
    {
        printf("学号: %s, 姓名: %s, 年龄: %d, 成绩: %.2f\n",
               students[i].ID,
               students[i].name,
               students[i].age,
               students[i].score);
    }
}

int main()
{
    struct Student students[MAX_STU];
    int count;

    // 1. 从键盘读入学生人数（不超过 MAX_STU）
    printf("请输入学生人数(不超过 %d)：", MAX_STU);
    scanf("%d", &count);
    // 安全检查，防止用户输入人数超过上限
    if (count > MAX_STU)
    {
        printf("输入人数超过上限 %d，程序退出。\n", MAX_STU);
        return 1;
    }

    // 2. 读入学生信息
    for (int i = 0; i < count; i++)
    {
        printf("\n请输入第 %d 个学生的信息：\n", i + 1);

        getchar(); // 吸收上一个输入遗留的换行符

        printf("学号: ");

        scanf("%s", students[i].ID);

        printf("姓名: ");
        scanf("%s", students[i].name);

        printf("年龄: ");
        scanf("%d", &students[i].age);

        printf("成绩: ");
        scanf("%lf", &students[i].score);
    }

    // 3. 调用 CreateFile 函数，将学生信息以二进制方式写入文件
    CreateFile(students, count);

    // 4. 再将文件中的信息读到内存，并输出
    //    ReadOut 函数也顺便返回了文件中实际读到的学生人数
    int realCount = ReadOut(students);

    // 5. 调用 Sort 函数，按成绩从高到低排序，并输出
    Sort(students, realCount);

    return 0;
}