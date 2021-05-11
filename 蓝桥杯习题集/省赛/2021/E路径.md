![](https://hairrrrr.gitee.io/img/1200/75.png)



```cpp
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>


using namespace std;

typedef long long LL;

const int N = 2030, M = N * 100;

int h[N], e[M], ne[M], w[M], idx;
int n = 2021; 
LL dist[N];
bool st[N];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

void add(int a, int b, int x)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = x, h[a] = idx++;
}

void spfa()
{
    for(int i = 1; i <= 2021; ++i) dist[i] = 1e18;
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    st[1] = true;
    
    while(q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        
        for(int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}


int main()
{
    memset(h, -1, sizeof h);
    
    for(int i = 1; i < n; ++i)
    {
        for(int j = i + 1; j <= min(i + 21, n); ++j)
        {
            int lcm = i * j / gcd(i, j);
            add(i, j, lcm), add(j, i, lcm);
        }
    }
   
    spfa();
    
    cout << dist[2021] << endl;
    
    return 0;
}
```

```
10266837
```