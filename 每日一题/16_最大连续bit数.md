链接：https://www.nowcoder.com/questionTerminal/4b1658fd8ffb4217bc3b7e85a38cfaf2
来源：牛客网



求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1

 本题含有多组样例输入。 



## 输入描述:

```
输入一个byte数字
```

## 输出描述:

```
输出转成二进制之后连续1的个数
```

示例1

## 输入

```
3
5
```

## 输出

```
2
1
```

## 说明

```
3的二进制表示是11，最多有2个连续的1。
5的二进制表示是101，最多只有1个连续的1。 
```



```cpp
#include<iostream>
using namespace std;
int main(void)
{
    int n;
    while (cin >> n)
    {
        int max = 0, cnt = 0, flg = 0;
        while (n != 0)
        {
            //cout << n << endl;
            if ((n & 1) == 1)
            {
                if (flg)
                    cnt++;
                else
                {
                    flg = 1;
                    cnt++;
                }
            }
            else
            {
                flg = 0;
                max = max > cnt ? max : cnt;
                cnt = 0;
            }
            // 退出前再更新一下 max
            if ((n >>= 1) == 0)
            {
                max = max > cnt ? max : cnt;
            }
        }
        cout << max << endl;
    }


    return 0;
}
```

还有一种更简洁的做法：

```cpp
链接：https://www.nowcoder.com/questionTerminal/4b1658fd8ffb4217bc3b7e85a38cfaf2
来源：牛客网

#include<iostream>
using namespace std;
int main()
{
    int byte;
    while(cin>>byte)
    {
        int k=0;
        for( k=0;byte!=0;k++)
        {
            byte=byte&(byte<<1);
        }
        cout<<k<<endl;
    }
    return 0;
}
```

