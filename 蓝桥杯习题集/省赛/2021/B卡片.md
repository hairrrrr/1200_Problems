![](https://hairrrrr.gitee.io/img/1200/72.png)



```cpp
#include<iostream>

using namespace std;

int cnt[10];

int main()
{
    for(int i = 0; i <= 9; ++i)
        cnt[i] = 2021;
    
    for(int i = 1; ; ++i)
    {
        int j = i;
        while(j)
        {
            if(cnt[j % 10]-- == 0)
            {
                cout << i - 1 << endl;
                return 0;
            }
            j /= 10;
        }
    }
    
    return 0;
}
```



```
3181
```

