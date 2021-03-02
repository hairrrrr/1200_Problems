// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=21&page=show_problem&problem=1935

#include<cstdio>

typedef long long ll;
ll ans;

ll f(x)
{
    if(x == 0) return 0;
    if(x % 10) return x % 10;
    return f(x / 10);
}

void solve(int l, int r)
{
    // 如果区间较小，直接计算
    if(r - l <= 9)
    {
        while(l <= r)
            ans += f(l), l++;
        return;
    }

    // 计算左区间 l 直到进位
    while(l % 10)
    {
        ans += l % 10;
        l++;
    }
    // 计算右区间 r 直到退位
    while(r % 10)
    {
        ans += r % 10;
        r--;
    }
    // 计算 l 和 r 之间的非 0 个位数
    // 1 + 2 + ... + 9 = 45
    ans += 45 * (r - l) / 10;
    
    solve(l / 10, r / 10);
}

int main(void)
{
    int l, r;
    while(scanf("%d %d", &l, &r) != EOF)
    {
        ans = 0; // 清零
        if(l == -1 && r == -1) return;
        printf("%lld\n", ans);       
    }    

    return 0;
}