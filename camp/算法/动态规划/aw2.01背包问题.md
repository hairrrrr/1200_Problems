---
tags: DP 01背包
---





有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。

第 i 件物品的体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

#### 输入格式

第一行两个整数，N，V 用空格隔开，分别表示物品数量和背包容积。

接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。

#### 输出格式

输出一个整数，表示最大价值。

#### 数据范围

`0<N,V≤1000`
`0<vi,wi≤1000`

#### 输入样例

```
4 5
1 2
2 4
3 4
4 5
```

#### 输出样例：

```
8
```

![](D:\图片\A pic\1200题\20.png)

**二维数组**

```cpp
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

int n, v;
// dp[i][j] 表示从前 i 个 物品中拿体积不超过 j 的物品的最大价值
int V[N], W[N], dp[N][N];

int main(void)
{
    cin >> n >> v;
    
    for(int i = 1; i <= n; ++i) cin >> V[i] >> W[i];
    
    // dp[a][b] 表示从前 a 个物品中拿小于等于 b 体积的物品的价值
    // dp[0][x] 表示从前 0 个物品中拿，所以价值应该是 0 .这一维应该初始化为 0 
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= v; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if(j >= V[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - V[i]] + W[i]);
        }
    }
    
    cout << dp[n][v] << endl;
    
    return 0;
}
```



**一维数组**

```cpp
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

int n, v;
int V[N], W[N], dp[N];

int main(void)
{
    cin >> n >> v;   
    
    for(int i = 1; i <= n; ++i) cin >> V[i] >> W[i];
    
	// 可以优化成 1 维的原因是：
    // 1.我们在计算 f[i][j] 时，只需要考虑 f[i - 1] 这一层
    // 2.f[i- 1][j] 和 f[i - 1][j - v[i]] 中的第二维是严格小于等于 j 的（不会出现在 j 两侧）
    for(int i = 1; i <= n; ++i)
    {
        for(int j = v; j >= V[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - V[i]] + W[i]);
        }
    }
    
    cout << dp[v] << endl;
    
    return 0;
}
```

