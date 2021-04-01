---
tags: DP 多重背包
---



有 N 种物品和一个容量是 V 的背包。

第 i 种物品最多有 si 件，每件体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

#### 输入格式

第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。

#### 输出格式

输出一个整数，表示最大价值。

#### 数据范围

0<N≤1000
0<V≤2000
0<vi,wi,si≤2000

##### 提示：

本题考查多重背包的二进制优化方法。

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

| 难度：**中等**          |
| ----------------------- |
| 时/空限制：1s / 64MB    |
| 总通过数：15061         |
| 总尝试数：32776         |
| 来源：背包九讲 , 模板题 |
| 算法标签                |

二进制优化，将对数量的枚举转化为 01 背包问题

```cpp
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

// 题目中 N 的最大值为 1000，s 的最大值是 2000 log 2000 上取整为 12 
// 一共可以把 1000 拆分成 12000 份
const int N = 12010, M = 2010;

int n, m;
int v[N], w[N], s[N];
int f[M];

int main(void)
{
    int n, m;
    cin >> n >> m;
    
    int cnt = 0;
    for(int i = 1; i <= n; ++i)
    {
        // 体积 价值 数量
        int a, b, s;
        cin >> a >> b >> s;
        
        int k = 1;
        while(k <= s)
        {
            cnt++;
            v[cnt] = k * a;
            w[cnt] = k * b;
            s -= k;
            k *= 2;
        }
        if(s > 0)
        {
            cnt++;
            v[cnt] = s * a;
            w[cnt] = s * b;
        }
    }
    
    n = cnt;
    
    for(int i = 1; i <= n; ++i)
        for(int j = m; j >= v[i]; --j)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
            
    cout << f[m] << endl;
    
    return 0;
}
```

