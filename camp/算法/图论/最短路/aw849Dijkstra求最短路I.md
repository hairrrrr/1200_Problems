---
tags: 图论 最短路
---



https://www.acwing.com/problem/content/851/



给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，所有边权均为正值。

请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 −1。

#### 输入格式

第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为  z。

#### 输出格式

输出一个整数，表示 1 号点到 n 号点的最短距离。

如果路径不存在，则输出 −1。

#### 数据范围

1≤n≤500
1≤m≤10^5
图中涉及边长均不超过10000。

#### 输入样例：

```
3 3
1 2 2
2 3 1
1 3 4
```

#### 输出样例：

```
3
```



```cpp
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 510, M = 100010;

int n, m;
// dist[i] 存储 1 号点到 i 的距离
int g[N][N], dist[N];
bool st[N];

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    for(int k = 0; k < n; ++k)
    {
        int j = -1;
        // 从不在最短路集合中寻找距离 1 最近的点
        for(int i = 1; i <= n; ++i)
            if(!st[i] && (j == -1 || dist[j] > dist[i]))
                j = i;
        
        st[j] = true; 
        
        // 如果已经确定了 1 到 n 的最短路退出循环 
        if(j == n) break;
        
        // 用 j 来更新其他点到 1 的距离
        for(int i = 1; i <= n; ++i)
            dist[i] = min(dist[i], dist[j] + g[j][i]);
    }
    
    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main(void)
{
    scanf("%d%d", &n, &m);
    
    memset(g, 0x3f, sizeof g);
    
    while(m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x][y] = min(g[x][y], z);
    }
    
    cout << dijkstra() << endl;
    
    return 0;
}
```

