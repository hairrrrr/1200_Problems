---
tags: 
---



![](https://hairrrrr.gitee.io/img/1200/50.png)

![](https://hairrrrr.gitee.io/img/1200/51.png)

#### 暴力

```cpp
#include<cstring>
#include<cstdio>

using namespace std;

const int N = 100010;

typedef long long LL;

char s[N];
bool st[26];

int main(void)
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
   
    LL ans = 0;
    // 字串区间起始位置
    for(int i = 1; i <= n; ++i)
    {
        memset(st, 0, sizeof st);
        LL sum = 1;
        st[s[i] - 'a'] = true;
        // 字串区间结束位置
        for(int j = i; j <= n; ++j)
        {
            if(!st[s[j] - 'a'])
            {
                sum++;
                st[s[j] - 'a'] = true;
                ans += sum;
            }
            else 
                ans += sum;
        }
    }
    
    printf("%d\n", ans);
}
```



#### 统计贡献

[题解](https://blog.csdn.net/qq_44691917/article/details/109339729)

```cpp
#include<cstring>
#include<cstdio>

using namespace std;

const int N = 100010;

typedef long long LL;

char s[N];
int st[26];

int main(void)
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
   
    LL ans = 0;
    
    for(int i = 1; i <= n; ++i)
    {
        ans += (i - st[s[i] - 'a']) * (n - i + 1);
        st[s[i] - 'a'] = i;
    }
    
    printf("%d\n", ans);
}
```

