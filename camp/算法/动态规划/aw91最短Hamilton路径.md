---
tags: 状压DP DP
---



### [91. 最短Hamilton路径](https://www.acwing.com/problem/content/93/)

给定一张 n 个点的带权无向图，点从 0∼n−1 标号，求起点 0 到终点 n−1 的最短 Hamilton 路径。

Hamilton 路径的定义是从 0 到 n−1 不重不漏地经过每个点恰好一次。

#### 输入格式

第一行输入整数 n。

接下来 n 行每行 n 个整数，其中第 i 行第 j 个整数表示点 i 到 j 的距离（记为 a[i,j]）。

对于任意的 x,y,z，数据保证 a[x,x]=0，a[x,y]=a[y,x] 并且 a[x,y]+a[y,z]≥a[x,z]。

#### 输出格式

输出一个整数，表示最短 Hamilton 路径的长度。

#### 数据范围

1≤n≤20
0≤a[i,j]≤10^7

#### 输入样例：

```
5
0 2 4 5 1
2 0 6 5 3
4 6 0 8 3
5 5 8 0 5
1 3 3 5 0
```

#### 输出样例：

```
18
```



![](D:\图片\图床\img\1200\101.png)

```cpp
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<iostream>

using namespace std;

const int N = 20;
int f[1 << N][N];
int w[N][N];

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> w[i][j];
    
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;
    
    for(int i = 0; i < 1 << n; ++i)
        // 从 0 走到 j 
        for(int j = 0; j < n; ++j)
            // j 必须在 i 中
            if(i >> j & 1)
                for(int k = 0; k < n; ++k)
                    // k 在 i 中
                    if(i >> k & 1)
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
    // 注意减去 1
    cout << f[(1 << n) - 1][n - 1] << endl;
    
    return 0;
}
```

