https://www.lanqiao.cn/problems/663/learning/



某君从某年开始每年都举办一次生日 party，并且每次都要吹熄与年龄相同根数的蜡烛。

现在算起来，他一共吹熄了 236 根蜡烛。

请问，他从多少岁开始过生日 party 的？

请输出他开始过生日 party 的年龄数。



```cpp
#include<cstring>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
	
	for(int i = 1; i <= 100; ++i)
	{
		int sum = 0;
		for(int j = i; j <= 100; ++j)
		{
			sum += j;
			if(sum == 236) 
			{
				cout << i << " " << j << endl;
				return 0;
			}
			if(sum > 236) break;
		}
	}
	
	return 0;
} 
```



[参考](https://blog.csdn.net/y1196645376/article/details/50938608)