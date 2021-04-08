---
tags: DFS
---



#### [93. 复原 IP 地址](https://leetcode-cn.com/problems/restore-ip-addresses/)



```
给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。

有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。

示例 1：

输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
示例 2：

输入：s = "0000"
输出：["0.0.0.0"]
示例 3：

输入：s = "1111"
输出：["1.1.1.1"]
示例 4：

输入：s = "010010"
输出：["0.10.0.10","0.100.1.0"]
示例 5：

输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]


提示：

0 <= s.length <= 3000
s 仅由数字组成
```



```cpp
class Solution {
public:
    vector<string> ans;
    string str;
    vector<string> restoreIpAddresses(string s) 
    {
        str = s;
        string path;
        int k = 0;
        dfs(0, path, k);
        return ans;
    }

    void dfs(int u, string path, int k)
    {
        if(k == 4 && u < str.size()) return;

        if(k == 4 && u == str.size())
        {
            ans.push_back(path.substr(1));
            return;
        }
        if(str[u] == '0') 
        {
            path += ".0";
            dfs(u + 1, path, k + 1);
        }
        else
        {
            int x = 0;
            for(int i = u; i < str.size(); ++i)
            {
                x = x * 10 + str[i] - '0';
                if(x > 255) break;
                dfs(i + 1, path + '.' + to_string(x), k + 1);
            }
        }
        
    }
};
```

