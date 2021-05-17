### [P1464 Function](https://www.luogu.com.cn/problem/P1464)



```cpp
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

const int N = 25;

typedef long long LL;

LL w[N][N][N];

int f(LL a, LL b, LL c)
{
    if(a <= 0 || b <= 0 || c <= 0) 
        return 1;
    
    if(a > 20 || b > 20 || c > 20)
    {
        if(w[20][20][20]) return w[20][20][20];
        w[20][20][20] = f(20, 20, 20);
        return w[20][20][20];
    }
    
    if(w[a][b][c]) return w[a][b][c];
    
    if(a < b && b < c)
        w[a][b][c] = f(a, b, c - 1) + f(a, b - 1, c - 1) - f(a, b - 1, c);
    else
        w[a][b][c] = f(a - 1, b, c) + f(a - 1, b - 1, c) + f(a - 1, b, c - 1)
        - f(a - 1, b - 1, c - 1);
    return w[a][b][c];
}

int main()
{   
    LL a, b, c;
    
    while(cin >> a >> b >> c, ~a | ~b | ~c)
    {
        printf("w(%lld, %lld, %lld) = %d\n", a, b, c, f(a, b, c));
    }
    
    return 0;
}
```

