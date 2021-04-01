---
tags: 快速幂
---





实现 pow(x, n) ，即计算 x 的 n 次幂函数。

```
示例 1:

输入: 2.00000, 10
输出: 1024.00000

示例 2:

输入: 2.10000, 3
输出: 9.26100

示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
```

说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/powx-n
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



**测试用例思考：**

- 如果幂为负数，转换为正数再计算。但是 `-2^31` 转为正数会溢出，需要使用 `long long` 来保存幂
- `0^0` 是 `1` 还是 `0` ?
- 溢出情况如何处理？（和面试官沟通）

算法：**快速幂** 时间复杂度:`O(logn)`

[题解](https://leetcode-cn.com/problems/powx-n/solution/powx-n-by-leetcode-solution/)

[参考文章](https://blog.csdn.net/qq_43827595/article/details/106157681)

迭代法：

```cpp
class Solution {
public:
    double myPow(double x, int n) 
    {
        double ans = 1;
        long long _pow = n;
        if(n < 0)
        {
            x = 1 / x;
            _pow *= -1;
        }
        while(_pow)
        {
            if(_pow & 1) ans *= x;
            x *= x;
            _pow >>= 1;
        }
        return ans;
    }
};
```

递归法：

```cpp
class Solution {
public:
    double myPow(double x, int n) 
    {
        long long _pow = n;
        return _pow >= 0 ? FastPow(x, _pow) : 1.0 / FastPow(x, -_pow);
    }
private:
    double FastPow(double x, long long n)
    {
        if(n == 0)
            return 1.0;
        double y = FastPow(x, n / 2);
        return n % 2 == 0 ? y * y : y * y * x; 
    }
};
```

