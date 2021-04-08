---
tags: DFS
---





#### [52. N皇后 II](https://leetcode-cn.com/problems/n-queens-ii/)



```
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。

示例 1：
输入：n = 4
输出：2
解释：如上图所示，4 皇后问题存在两个不同的解法。

示例 2：
输入：n = 1
输出：1

提示：
1 <= n <= 9
皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
```



```cpp
class Solution {
public:
    vector<bool> col, bg, ubg;
    int ans, n;
    int totalNQueens(int _n) 
    {
        n = _n;
        col.resize(n), bg.resize(2 * n), ubg.resize(2 * n);
        dfs(0);        
        return ans;
    }

    void dfs(int u)
    {
        if(u == n)
        {
            ans++;
            return;
        }
        
        for(int i = 0; i < n; ++i)
            if(!col[i] && !bg[u + i] && !ubg[n + u - i])
            {
                col[i] = bg[u + i] = ubg[n + u - i] = true;
                dfs(u + 1);
                col[i] = bg[u + i] = ubg[n + u - i] = false;
            }
    }
};
```



```cpp
class Solution {
public:
    vector<bool> row, col, bg, ubg;
    int n, ans;
    int totalNQueens(int _n) 
    {
        n = _n, ans = 0;
        row.resize(n), col.resize(n), bg.resize(2 * n), ubg.resize(2 * n);
        dfs(0, 0, 0);
        return ans;
    }

    void dfs(int x, int y, int s)
    {
        if(y >= n) y = 0, x++;
        if(x >= n)
        {
            if(s == n) ans++;
            return;
        }

        dfs(x, y + 1, s);

        if(!row[x] && !col[y] && !bg[x + y] && !ubg[n + x - y])
        {
            row[x] = col[y] = bg[x + y] = ubg[n + x - y] = true;
            dfs(x, y + 1, s + 1);
            row[x] = col[y] = bg[x + y] = ubg[n + x - y] = false;
        } 
    }
};
```

