#include <stdio.h>

typedef struct Date
{
    int year;
    int month;
    int day;
} Date;

int isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return 1;
    }
    return 0;
}

int checkDate(Date date)
{
    int year = date.year;
    int month = date.month;
    int day = date.day;

    if (year < 1 || year > 9999)
    {
        return 0;
    }

    if (month < 1 || month > 12)
    {
        return 0;
    }

    int daysInMonth;
    switch (month)
    {
    case 2: // 二月
        daysInMonth = isLeapYear(year) ? 29 : 28;
        break;
    case 4:  // 四月
    case 6:  // 六月
    case 9:  // 九月
    case 11: // 十一月
        daysInMonth = 30;
        break;
    default: // 其他月份 1,3,5,7,8,10,12
        daysInMonth = 31;
        break;
    }

    // 检查日
    if (day < 1 || day > daysInMonth)
    {
        return 0;
    }

    // 如果所有检查都通过，则返回真（1 表示合法）
    return 1;
}

int main()
{
    Date date;
    int isValid = 0; // 标志位：0 表示无效，需要继续输入

    while (!isValid)
    {
        printf("请输入日期（格式：年 月 日）：");
        // 从标准输入获取用户输入的年月日
        scanf("%d %d %d", &date.year, &date.month, &date.day);

        // 调用 checkDate 函数验证是否正确
        if (checkDate(date))
        {
            printf("您输入的日期正确：%04d-%02d-%02d\n", date.year, date.month, date.day);
            isValid = 1; // 如果合法，则置标志位为 1 以退出循环
        }
        else
        {
            printf("输入的日期不合法，请重新输入！\n");
        }
    }

    return 0;
}