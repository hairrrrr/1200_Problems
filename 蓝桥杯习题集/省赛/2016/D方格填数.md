

https://www.lanqiao.cn/problems/664/learning/



```
   +--+--+--+
   |  |  |  |
+--+--+--+--+
|  |  |  |  |
+--+--+--+--+
|  |  |  |
+--+--+--+
```

填入 0 ~ 9 的数字。要求：连续的两个数字不能相邻。 （左右、上下、对角都算相邻）

一共有多少种可能的填数方案？



```cpp
#include<cstring>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<iostream>

using namespace std;

bool flg[3][4];// 记录那些格子可以放 
bool st[10]; 
int way[3][4], ans;

void init()
{
	flg[0][0] = flg[2][3] = 1;
}


void solve()
{
	int dx[] = {1, -1, 0, 0, -1, -1, 1, 1}, dy[] = {0, 0, -1, 1, 1, -1, -1, 1};
	
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 4; ++j)
		{
			if(flg[i][j]) continue;
			bool f = false;
			for(int k = 0; k < 8; ++k)
			{
				int x = i + dx[k], y = j + dy[k];
				if(x < 0 || x >= 3 || y < 0 || y >= 4 || flg[x][y]) continue;
				if(abs(way[x][y] - way[i][j]) == 1) 
				{
					f = true;
					break;
				}
			}
			if(f)
				return;
		}
	ans++;
}


void dfs(int u)
{
	int x = u / 4, y = u % 4;
	
	if(x == 3)
	{
		solve();
		return;
	}	
	
	if(!flg[x][y])
	{
		for(int i = 0; i < 10; ++i)
		{
			if(!st[i])
			{
				st[i] = true;
				way[x][y] = i;
				dfs(u + 1);
				st[i] = false;
			}
		}
	}
	else
		dfs(u + 1);
}

int main()
{
	init();
	
	dfs(0);
	
	cout << ans << endl;
	
	return 0;
}
```


[参考](https://blog.csdn.net/y1196645376/article/details/50938608)