![](https://hairrrrr.gitee.io/img/1200/74.png)





```cpp
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long LL;

LL n = 2021041820210418;

int main()
{
    vector<LL> factor;
    
    // i * i 会溢出
    for(int i = 1; (LL)i * i <= n; ++i)
    {
        if(n % i == 0) 
		{
			factor.push_back(i);
			if(n / i != i) factor.push_back(n / i);
		}
        
    }
    
    int res = 0;
    for(auto a : factor)
        for(auto b : factor)
        {
            LL c = n / a / b;
            // 如果 a * b 大于 n，那么 c 为 0 .不存在溢出问题
            if(a * b * c == n) res++;
        }
        
    cout << res << endl;
    
    return 0;
}
```



```
2430
```

 

