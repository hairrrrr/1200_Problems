如下图所示，小明用从 11 开始的正整数“蛇形”填充无限大的矩阵。

```txt
1 2 6 7 15 ...
3 5 8 14 ...
4 9 13 ...
10 12 ...
11 ...
...
```

容易看出矩阵第二行第二列中的数是 5。请你计算矩阵中第 20 行第 20 列的数是多少？



#### 找规律

```cpp
#include <iostream>
using namespace std;
int main()
{
  int res = 1;
  int n = 4;
  for(int i = 1; i < 20; ++i)
  {
    res += n;
    n += 4;
  } 

  cout << res << endl;

  return 0;
}
```



#### 模拟

```cpp

```

