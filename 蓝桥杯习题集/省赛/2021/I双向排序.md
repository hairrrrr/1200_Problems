![](https://hairrrrr.gitee.io/img/1200/79.png)



```cpp
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;

#define x first
#define y second

typedef pair<int, int> PII;

int n, m, top;
int ans[N];
PII stk[N];

int main()
{
    scanf("%d%d", &n, &m);
    
    while(m--)
    {
        int p, q;
        scanf("%d%d", &p, &q);
        if(!p)
        {
            while(top && stk[top].x == 0) q = max(stk[top--].y, q);
            while(top >= 2 && stk[top - 1].y <= q) top -= 2;
            stk[++top] = {p, q};
        }
        // 第一次操作一定为前缀操作
        else if(top)
        {
            while(top && stk[top].x == 1) q = min(q, stk[top--].y);
            while(top >= 2 && stk[top - 1].y >= q) top -= 2;
            stk[++top] = {p, q};
        }
    }
    
    int d = n, l = 1, r = n;
    for(int i = 1; i <= top; ++i)
    {
        if(stk[i].x == 0)
            while(l <= r && stk[i].y < r) ans[r--] = d--;
        else 
            while(l <= r && l < stk[i].y) ans[l++] = d--;
        if(l > r) break;
    }
    
    // 如果最后一次操作为前缀，下一次操作为后缀
    if(stk[top].x == 0)
        while(l <= r) ans[l++] = d--;
    else 
        while(l <= r) ans[r--] = d--;
        
    for(int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    
    return 0;
}
```



[题解](https://www.acwing.com/solution/content/48049/)

