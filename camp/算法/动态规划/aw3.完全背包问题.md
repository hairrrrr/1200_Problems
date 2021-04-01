---
tags: DP 完全背包
---



https://www.acwing.com/problem/content/3/



有 N 种物品和一个容量是 V 的背包，每种物品都有无限件可用。

第 i 种物品的体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

#### 输入格式

第一行两个整数，N，V用空格隔开，分别表示物品种数和背包容积。

接下来有 NN 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 种物品的体积和价值。

#### 输出格式

输出一个整数，表示最大价值。

#### 数据范围

0<N,V≤1000
0<vi,wi≤1000

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
10
```

#### 暴力

时间复杂度，最坏：`O(n*v^2)`

![](D:\图片\A pic\1200题\39.png)



```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

int f[N][N], w[N], v[N];

int main(void)
{
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
    
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <= m; ++j)
            for(int k = 0; k * v[i] <= j; ++k)
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + k * w[i]);
                
    cout << f[n][m] << endl;
    
    return 0;
}
```

#### 优化

时间复杂度：`O(n^2)`

![](D:\图片\A pic\1200题\40.png)



```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

int f[N][N], w[N], v[N];

int main(void)
{
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
    
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <= m; ++j)
        {
            f[i][j] = f[i - 1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
        }
                
    cout << f[n][m] << endl;
    
    return 0;
}
```



优化成 1 维 ：

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

int f[N], w[N], v[N];

int main(void)
{
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
    
    for(int i = 1; i <= n; ++i)
        for(int j = v[i]; j <= m; ++j)
        {
            // 计算 f[j] 时，f[j] 保存的还是上一层的值即 f[i - 1][j]
            // 由于 f[j - v[i] 小于 f[j] 
            // 所以计算 f[j] 时 f[j - v[i]] 已经更新，即 f[i][j - v[i]]  
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
                
    cout << f[m] << endl;
    
    return 0;
}
```



