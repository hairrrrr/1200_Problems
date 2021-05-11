![](https://hairrrrr.gitee.io/img/1200/76.png)



```cpp
#include<iostream>

using namespace std;


int main()
{
    long long t;
    cin >> t;
    
    t /= 1000; // 毫秒转化为秒
    t %= 24 * 60 * 60;
    
    int h = t / 3600;
    t %= 3600;
    int m = t / 60;
    t %= 60;
    
    printf("%02d:%02d:%02d\n", h, m, t);
    
    return 0;
}
```

