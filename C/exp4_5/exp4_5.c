#include <stdio.h>
#include <math.h>

// 判断一个数是否是质数的函数
int isPrime(int n)
{
    if (n < 2)
        return 0; // 1 和小于 1 的数都不是质数
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0; // 有因子则不是质数
        }
    }
    return 1; // 是质数
}

// 主函数
int main()
{
    // 遍历 4 到 2000 的所有正偶数
    for (int even = 4; even <= 2000; even += 2)
    {
        for (int i = 2; i <= even / 2; i++)
        {
            // 判断是否能分解为两个质数之和
            if (isPrime(i) && isPrime(even - i))
            {
                printf("%d = %d + %d\n", even, i, even - i);
                break; // 找到一种分解后停止
            }
        }
    }
    return 0;
}