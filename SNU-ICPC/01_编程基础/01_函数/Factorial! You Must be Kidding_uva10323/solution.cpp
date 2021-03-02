// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1264&mosmsg=Submission+received+with+ID+25963997
// 需要注意负数的阶乘

// 首先求出阶乘比 6227020800 小的最后一数的和阶乘比 10000 大的第一个数
// void fact()
// {
//     int i = 1;
//     long long sum = 1;
//     while(1)
//     {
//         sum *= i;
//         if(sum >= 10000) printf("%d ", i);
//         if(sum > 6227020800) 
//         {
//             printf("%d", i);
//             break;
//         }
//         ++i;
//     }
// }

// 当 n 满足 [8, 13] 时，有 [10000, 6227020800]
// f(0) = 1 
// f(0) = 0 * f(-1)  f(-1) = f(0) / 1 趋近于正无穷
// f(-1) = -1 * f(-2) f(-2) = f(-1) / -1 趋近于负无穷
#include<cstdio>

int main(void)
{
    long long num[14];
    num[0] = 1;
    for(int i = 1; i < 14; ++i)
    {
        num[i] *= num[i - 1];
    }
    int n;
    while(~scanf("%d", &n))
    {
        if(n < 8 || (n < 0 && -n % 2 == 1)) printf("Underflow!\n");
        if(n > 13 || (n < 0 && -n % 2 == 0)) printf("Overflow!\n");
        else printf("%d\n", num[n]);
    }

    return 0;
}