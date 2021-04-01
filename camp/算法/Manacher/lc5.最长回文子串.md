---
tags: Manacher DP 区间DP
---





#### [5. 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)



给你一个字符串 s，找到 s 中最长的回文子串。

 ```
示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。

示例 2：

输入：s = "cbbd"
输出："bb"

示例 3：

输入：s = "a"
输出："a"

示例 4：

输入：s = "ac"
输出："a"
 ```


提示：

1 <= s.length <= 1000
s 仅由数字和英文字母（大写和/或小写）组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

题解：

- [官方](https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/)
- [weiwei哥](https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zhong-xin-kuo-san-dong-tai-gui-hua-by-liweiwei1419/)

#### dp

集合划分：`f(i, j)` 区间 `i, j` 是不是一个回文串

集合属性：Max

状态计算：`f(i, j) = (s[i] == s[j]) && f(i + 1, j - 1)`

```cpp
class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.length();
        vector<vector<int>> f(n + 1, vector<int>(n + 1));
        string ans;
        s = "0" + s;
        // 枚举区间长度
        for(int len = 0; len < n; ++len)
        {
            for(int l = 1; l + len <= n; ++l)
            {
                int r = l + len;
                if(len == 0)
                    f[l][r] = 1;
                else if(len == 1)
                    f[l][r] = s[l] == s[r];
                else 
                    f[l][r] = (s[l] == s[r]) && f[l + 1][r - 1];
                if(f[l][r] && len + 1 > ans.length())
                    // l 下标从 1 开始
                    ans = s.substr(l, len + 1);
            }
            
        }
        return ans;
    }
};
```

