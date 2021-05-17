### [P1055 [NOIP2008 普及组] ISBN 号码](https://www.luogu.com.cn/problem/P1055)



用 `getline` 读 4 8 过不了

```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    int t = 3;
    int x = 0, j = 1;
    for(int i = 0; t; ++i)
    {
        if(s[i] == '-') 
        {
            t--;
            continue;
        }
        x += (s[i] - '0') * j++;
    }
    
    x %= 11;
    
    char ch;
    if(x == 10) ch = 'X';
    else ch = x + '0';
    
    if(ch == s[s.length() - 1]) cout << "Right" << endl;
    else cout << s.substr(0, s.length() - 1) << ch << endl;
    
    return 0;
}
```

