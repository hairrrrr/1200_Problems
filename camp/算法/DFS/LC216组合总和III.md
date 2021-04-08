---
tags: DFS
---



#### [216. 组合总和 III](https://leetcode-cn.com/problems/combination-sum-iii/)



```
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：
所有数字都是正整数。
解集不能包含重复的组合。 

示例 1:
输入: k = 3, n = 7
输出: [[1,2,4]]

示例 2:
输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
```



```cpp
class Solution {
public:
    vector<vector<int>> ans;
    int n, k;
    vector<bool> st;
    vector<int> path;
    vector<vector<int>> combinationSum3(int _k, int _n) 
    {
        k = _k, n = _n;
        st.resize(10), path.resize(k);
        dfs(0, 1);
        
        return ans;
    }

    void dfs(int u, int start)
    {
        if(u == k)
        {
            int sum = 0;
            for(int i = 0; i < k; ++i) sum += path[i];
            if(sum == n) ans.push_back(path);
            return;
        }

        for(int i = start; i <= 9; ++i)
        {
            if(i > n) break;
            path[u] = i;
            dfs(u + 1, i + 1);
        }
    }
};
```



