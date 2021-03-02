#include<cstdio>

int conversion(int num, int scale)
{
    int ans = 0;
    while(num)
    {
        ans += num % scale;
        num /= scale;
    }
    return ans;
}

int main(void)
{
    for(int i = 2992; i < 10000; ++i)
    {
        int scale10 = conversion(i, 10);
        if(scale10 == conversion(i, 12) && scale10 == conversion(i, 16))
            printf("%d\n", i);
    }
    
    return 0;
}