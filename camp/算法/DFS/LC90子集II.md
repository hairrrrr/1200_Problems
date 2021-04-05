---
tags: DFS
---



#### [90. 子集 II](https://leetcode-cn.com/problems/subsets-ii/)



给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

 ```
示例 1：

输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]

示例 2：

输入：nums = [0]
输出：[[],[0]]
 ```




提示：

```
1 <= nums.length <= 10
-10 <= nums[i] <= 10
```



```cpp
class Solution 
{
    unordered_map<int, int> cnt;
    vector<vector<int>> ans;
    vector<int> path;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        for(auto e : nums) cnt[e]++;
        dfs(-10);
        return ans;
    }

    void dfs(int u)
    {
        if(u > 10) ans.push_back(path);
        else
        {
            // 每个数有 [0, cnt[u]] 种选择
            for(int i = 0; i <= cnt[u]; ++i)
            {
                dfs(u + 1);
                path.push_back(u);
            }
            // 回溯
            for(int i = 0 ; i <= cnt[u]; ++i)
                path.pop_back();
        }
    }
};
```

