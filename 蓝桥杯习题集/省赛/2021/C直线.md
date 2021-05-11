![](https://hairrrrr.gitee.io/img/1200/73.png)



本题的坑：

- 计算斜率时，x 如果相同则斜率不存在，需要特判
- `double` 存在精度问题，不能直接使用 `==` 判等。判断方法：做差小于 `1e-8` 

```cpp
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

// 420 个点确定的直线数不超过 419^2  
const int N = 175561;

struct Line
{
    double k, b;
    bool operator<(const Line& L) const 
    {
        if(fabs(k - L.k) > 1e-8) return k < L.k;
        return b < L.b;
    }
}l[N];

int main()
{
    int n = 0;
    
    // 这样枚举会造成很多重复
    for(int x1 = 0; x1 < 20; ++x1)
        for(int y1 = 0; y1 < 21; ++y1)
            for(int x2 = 0; x2 < 20; ++x2)
                for(int y2 = 0; y2 < 21; ++y2)
                {
                    if(x2 != x1)
                    {
                        // 计算 k 时，相同的两个点会计算出不同的 k。但是这个不同的 k 是存在于解中的
                        double k = double(y1 - y2) / (x1 - x2);
                        double b = y1 - k * x1;
                        l[n++] = {k, b};
                    }
                }
    
    sort(l, l + n);

    // 第一条直线一定是不重复的
    int res = 1;
    for(int i = 1; i < n; ++i)
        if(fabs(l[i - 1].k - l[i].k) > 1e-8 || fabs(l[i - 1].b - l[i].b) > 1e-8)
            res++;
    
    // 20 条垂直 x 轴的直线
    cout << res + 20 << endl;
    return 0;
}
```



```
40257
```





```cpp
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;

// 420 个点确定的直线数不超过 419^2  
const int N = 175561;

struct Line
{
    double k, b;
    bool operator<(const Line& L) const 
    {
        if(fabs(k - L.k) > 1e-8) return k < L.k;
        return b < L.b;
    }
}l[N];

PII points[N];

int main()
{
    int n = 0, m = 0;
    
    // 枚举所有点
    for(int i = 0; i < 20; ++i)
        for(int j = 0; j < 21; ++j)
            points[n++] = {i, j};
	
    // 枚举所有可能的直线
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < i; ++j)
            if(points[i].x != points[j].x)
            {
                PII& a = points[i], b = points[j];
                double k = double(a.y - b.y) / (a.x - b.x);
                double bb = a.y - k * a.x;
                l[m++] = {k, bb};
            }
    
    sort(l, l + m);

    // 第一条直线一定是不重复的
    int res = 1;
    for(int i = 1; i < m; ++i)
        if(fabs(l[i - 1].k - l[i].k) > 1e-8 || fabs(l[i - 1].b - l[i].b) > 1e-8)
            res++;
    
    // 20 条垂直 x 轴的直线
    cout << res + 20 << endl;
    return 0;
}
```



