https://www.lanqiao.cn/problems/667/learning/



有一堆煤球，堆成三角棱锥形。具体： 第一层放 1 个， 第二层 3 个（排列成三角形）， 第三层 6 个（排列成三角形）， 第四层 10 个（排列成三角形）， .... 如果一共有 100 层，共有多少个煤球？



```cpp
#include<cstring>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
	int sum = 1;
	int level = 1, step = 2;
	for(int i = 0; i < 99; ++i)
	{
		level += step;
		sum += level;
		step++;
	}
	
	cout << sum << endl;
	
	return 0;
} 
```



[参考](https://blog.csdn.net/y1196645376/article/details/50938608)