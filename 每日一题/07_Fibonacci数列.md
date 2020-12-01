链接：https://www.nowcoder.com/questionTerminal/18ecd0ecf5ef4fe9ba3f17f8d00d2d66
来源：牛客网



Fibonacci数列是这样定义的：
  F[0] = 0
  F[1] = 1
  for each i ≥ 2: F[i] = F[i-1] + F[i-2]
  因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。

## 输入描述:

```
输入为一个正整数N(1 ≤ N ≤ 1,000,000)
```

## 输出描述:

```
输出一个最小的步数变为Fibonacci数"
```

示例1

## 输入

```
15
```

## 输出

```
2
```

```cpp
#include<iostream>
using namespace std;
int a[100];
int main(void)
{
    a[1] = 1;
    int n;
    cin >> n;
    int small = 1, big = 1;
    int i = 1;
    while (n > a[i])
    {
        a[++i] = a[i - 1] + a[i - 2];
        if (n > a[i])
            small = a[i];
        else
            big = a[i];
    }
    int step = (n - small > big - n) ? big - n : n - small;
    cout << step << endl;
}
```

这样写在我的编译器（VS）上运行正确，但是在平台上过不了。后来经过群友大佬的指点，发现错在 `a[++i] = a[i - 1] + a[i - 2];` 

`++` 在不同编译器下实现不同，不要把 `++` 写在一句话里！

所以改成：

```cpp
 while (n > a[i])
    {
        ++i;
        a[i] = a[i - 1] + a[i - 2];
        if (n > a[i])
            small = a[i];
        else
            big = a[i];
    }
```

就过了！

优化一下空间效率：使用迭代法

```cpp
#include<iostream>
using namespace std;

int main(void)
{
    int f0 = 0, f1 = 1, f;
    int n;
    cin >> n;
    int small = 1, big = 1;
    while (n > f1)
    {
        f = f0 + f1;
        f0 = f1;
        f1 = f;
        if (n > f)
            small = f;
        else
            big = f;
    }
    int step = n - small > big - n ? big - n : n - small;
    cout << step << endl;
}
```

