https://www.lanqiao.cn/problems/646/learning/



2,3,5,7,11,13,.... 是素数序列。 类似：7,37,67,97,127,157 这样完全由素数组成的等差数列，叫等差素数数列。

上边的数列公差为 30，长度为 6。

2004 年，格林与华人陶哲轩合作证明了：存在任意长度的素数等差数列。 这是数论领域一项惊人的成果！

有这一理论为基础，请你借助手中的计算机，满怀信心地搜索：

长度为 10 的等差素数列，其公差最小值是多少？



```cpp
#include<cstring>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<iostream>

using namespace std;

const int N = 10010;

int prim[N], cnt;
// 0 1 不是素数 
bool dp[N] = {1 , 1, 0};

void init()
{
	for(int i = 2; i < N; ++i)
	{
		if(dp[i]) continue;
		prim[cnt++] = i;
		for(int j = i; j * i < N; ++j)
			dp[j * i] = true;
	}
	cout << 4 << endl;
}

int main()
{
	init();
	
	
	// 枚举公差 
	for(int i = 1; i * 9 < N; ++i)
	{
		// 枚举所有素数作为起始位置
		for(int j = 0; j + 10 - 1 < cnt; ++j)
		{
			int now = prim[j];
			bool flg = true;
			for(int k = 1; k <= 9; ++k)
			{
				if(now + i > N || dp[now + i] == true) 
				{
					flg = false;
					break;
				}
				now += i;
			}
			if(flg)
			{
				cout << "d = " << i << " a0 = " << prim[j] << endl;
				return 0; 
			}
		} 
		 
	}
	
	return 0;
} 
```



[参考](https://blog.csdn.net/y1196645376/article/details/50938608)