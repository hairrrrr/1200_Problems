### [P1014 [NOIP1999 普及组] Cantor 表](https://www.luogu.com.cn/problem/P1014)



```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a = 1, b = 1;
    
    n--;
    while(n)
    {
        b++;
        while(--n && b != 1) b--, a++;
        if(!n) break;
        a++;
        while(--n && a != 1) a--, b++;
    }
    
    cout << a << "/" << b << endl;
    
    return 0;
}
```

