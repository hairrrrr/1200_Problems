![](https://hairrrrr.gitee.io/img/1200/77.png)



![](D:\图片\图床\img\1200\100.png)



```cpp
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int N = 110, M = 100010;

int n, m;
int w[N];
bool dp[N][2 * M];

int main()
{
    cin >> n;
    
    for(int i = 1; i <= n; ++i) cin >> w[i], m += w[i];

    // M 是偏移量，将 [-M ~ M] 映射为 [0 ~ 2M]
    dp[0][M] = true;
    for(int i = 1; i <= n; ++i)
        for(int j = -m; j <= m; ++j)
        {
            // 不选
            dp[i][j + M] |= dp[i - 1][j + M];
            // 加
            if(j - w[i] >= -m) dp[i][j + M] |= dp[i - 1][j - w[i] + M];
            // 减
            if(j + w[i] <= m) dp[i][j + M] |= dp[i - 1][j + w[i] + M];
        }
        
    int res = 0;
    
    for(int i = 1; i <= m; ++i) 
        if(dp[n][i + M]) res++;
        
    cout << res << endl;
    
    return 0;
}
```

