
[OJ 链接](https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?orderByHotValue=1&page=1&onlyReference=false)

```cpp
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
    int n;
    vector<int> v;
    while (cin >> n)
    {
        v.resize(3 * n);
        for (int i = 0; i < 3 * n; i++)
        {
            cin >> v[i];
        }

        //排序
        sort(v.begin(), v.end());

        // sumMax 的数据类型应该足够大
        size_t sumMax = 0;
        // 每组的最小元素从区间 [0, n - 1] 中获得
        // [n, 3n - 1] 每两个取后一个（中间元素）
        for (int i = n; i < 3 * n - 1; i += 2)
        {
            sumMax += v[i];
        }

        cout << sumMax << endl;
    }

    return 0;
}
```