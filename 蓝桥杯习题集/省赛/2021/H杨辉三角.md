![](https://hairrrrr.gitee.io/img/1200/78.png)



```cpp
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;

int n;

LL C(int a, int b)
{
    LL res = 1;
    for(int i = a, j = 1; j <= b; ++j, --i)
    {
        res = res * i / j;
        if(res > n) return res;
    }
    return res;
}

bool check(int k)
{
    // C[l, k] 到 C[r, k] 单调，可以使用二分
    LL l = 2 * k, r = max((LL)n, l);
    while(l < r)
    {
        LL mid = l + r >> 1;
        if(C(mid, k) >= n) r = mid;
        else l = mid + 1;
    }
    
    if(C(r, k) == n)
    {
        // 第 l 行前有 l 行，每行元素为 1 2 。。。l
        cout << (1 + l) * l / 2 + k + 1 << endl;
        return true;
    }
    
    return false;
}

int main()
{
    cin >> n;
    
    // 从大到小枚举所有斜线（n 一定最先出现在最大的斜线中）
    for(int k = 16; k >= 0; --k)
    {
        if(check(k)) break;
    }
    
    return 0;
}
```



[题解](https://www.acwing.com/solution/content/47358/)

