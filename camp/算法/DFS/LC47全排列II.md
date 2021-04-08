---
tags: DFS
---





给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

 ```
示例 1：
输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]

示例 2：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


提示：
1 <= nums.length <= 8
-10 <= nums[i] <= 10
 ```



#### 枚举每个位置可以放那个元素

```cpp
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> st;
    int n;
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        n = nums.size();
        path.resize(n), st.resize(n, false);
        dfs(nums, 0);

        return ans;
    }

    void dfs(vector<int>& nums, int u)
    {
        if(u == n)
        {
            ans.push_back(path);
            return;
        }
        // 用来记录这一层那些数字已经被放过
        unordered_set<int> s;
        // 枚举每个位置可以放那个元素
        for(int i = 0; i < n; ++i)
        {
            // 每一次相同的数只放一次
            if(!st[i] && !s.count(nums[i]))
            {
                st[i] = true;
                path[u] = nums[i];
                s.insert(nums[i]);
                dfs(nums, u + 1);
                st[i] = false;
            }
        }
    }
};
```



#### 枚举每个元素可以放在那个位置

```cpp
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> st;
    int n;
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        n = nums.size();
        path.resize(n), st.resize(n, false);
        sort(nums.begin(), nums.end());
        dfs(nums, 0, 0);

        return ans;
    }

    void dfs(vector<int>& nums, int u, int start)
    {
        if(u == n)
        {
            ans.push_back(path);
            return;
        }
        // 枚举每个数组元素可以放在哪一位
        for(int i = start; i < n; ++i)
        {
            if(!st[i])
            {
                st[i] = true;
                path[i] = nums[u];
                if(u + 1 < n && nums[u + 1] == nums[u]) dfs(nums, u + 1, i + 1);
                else dfs(nums, u + 1, 0);
                st[i] = false;
            }
        }
    }
};
```

