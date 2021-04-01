---
tags: DP 多重背包
---



https://www.acwing.com/problem/content/4/



有 NN 种物品和一个容量是 VV 的背包。

第 i 种物品最多有 si 件，每件体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

#### 输入格式

第一行两个整数，N，VN，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。

#### 输出格式

输出一个整数，表示最大价值。

#### 数据范围

0<N,V≤100
0<vi,wi,si≤100

#### 输入样例

```
4 5
1 2 3
2 4 1
3 4 3
4 5 2
```

#### 输出样例：

```
10
```

| 难度：**简单**          |
| ----------------------- |
| 时/空限制：1s / 64MB    |
| 总通过数：18924         |
| 总尝试数：33785         |
| 来源：背包九讲 , 模板题 |
| 算法标签                |



```cpp
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 110;

int n, m;
int v[N], w[N], s[N];
int f[N][N];

int main(void)
{
    cin >> n >> m;
    
    for(int i = 1; i <= n; ++i) scanf("%d%d%d", &v[i], &w[i], &s[i]);
    
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= m; ++j)
        {
            for(int k = 0; k <= s[i] && k * v[i] <= j; ++k)
            {
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }
    
    cout << f[n][m] << endl;
    
    return 0;
}
```

