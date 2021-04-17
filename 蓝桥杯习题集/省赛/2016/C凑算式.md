```
     B      DEF
A + --- + ------- = 10
     C      GHI
```

这个算式中 A ~ I 代表 0 ~ 9 的数字，不同的字母代表不同的数字。

比如： `6+8/3+952/714` 就是一种解法， `5+3/1+972/486` 是另一种解法。

这个算式一共有多少种解法？



这题目没表达清楚，题目中说 A ~ I 表示 `0 ~ 9` 的数字，但是实际上不能表示 0 

然后要注意的是 A ~ I 都应该用 double 来表示

```cpp
#include<cstring>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<iostream>

using namespace std;

bool st[10];
double nums[10];
int ans;

void dfs(int u)
{
	if(u == 9) 
	{
		double a, b, c, d, e;
		a = nums[0];
		b = nums[1],c = nums[2];
		d = 0, e = 0;
		for(int i = 3; i < 6; ++i)
			d = d * 10 + nums[i];
		for(int i = 6; i < 9; ++i)
			e = e * 10 + nums[i];	
		if(a + b / c + d / e == 10.0) 
		{
			ans++;
		}
		
		return;
	}
	
	for(int i = 1; i < 10; ++i)
	{
		if(!st[i])
		{
			st[i] = true;
			nums[u] = i;
			dfs(u + 1);
			st[i] = false;
		}
	}
	
}

int main()
{
	dfs(0);
	
	cout << ans << endl;
	
	
	return 0;
} 
```



[参考](https://blog.csdn.net/y1196645376/article/details/50938608)