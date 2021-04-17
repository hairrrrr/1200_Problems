如【图1.jpg】, 有12张连在一起的12生肖的邮票。
现在你要从中剪下5张来，要求必须是连着的。
（仅仅连接一个角不算相连）
比如，【图2.jpg】，【图3.jpg】中，粉红色所示部分就是合格的剪取。



![](https://hairrrrr.gitee.io/img/1200/2.jpg)

![](https://hairrrrr.gitee.io/img/1200/3.jpg)

![](https://hairrrrr.gitee.io/img/1200/4.jpg)

请你计算，一共有多少种不同的剪取方法。

请填写表示方案数目的整数。

注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。



```cpp
#include<cstring>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<iostream>
#include<unordered_set>
#include<queue>

using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;

int way[5], nums[3][4], ans;

void init()
{
	int k = 0;
	// 将方格中的数映射为 0 ~ 11 方便处理数和下标的关系 
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 4; ++j)
			nums[i][j] = k++;
}

void solve()
{
	int st[3][4];
	
	memset(st, 0, sizeof st);
	
	// 采用 bfs，2 表示可以走的路 
	for(int i = 0; i < 5; ++i)
	{
		st[way[i] / 4][way[i] % 4] = 2;
	}
	
	queue<PII> q;
	int cnt = 0;
	int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
	
	// 将数组中的第一个数作为起点 
	PII start = {way[0] / 4, way[0] % 4};
	q.push(start);
	// 起点标记为访问过 
	st[start.x][start.y] = 1;
	cnt++;
	
	while(q.size())
	{
		PII t = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i)
		{
			int a = t.x + dx[i], b = t.y + dy[i];
			if(a < 0 || a >= 3 || b < 0 || b >= 4) continue;
			if(st[a][b] != 2) continue;
			
			q.push({a, b});
			cnt++;
			st[a][b] = 1;
		}
	}
	// 如果搜索到的点的数量等于 5，则说明是连通的 
	if(cnt == 5) ans++;
}

void dfs(int u, int start)
{
	if(u == 5)
	{
		solve();
		return;
	}
	
	// 5 - u > 12 - start
	// 如果剩下的数不够 5 位，则直接返回 
	if(5 - u > 12 - start) return;
		
	for(int i = start; i < 12; ++i)
	{
		way[u] = i;	
		dfs(u + 1, i + 1);
	}
}

int main()
{
	init();
	
	dfs(0, 0);
	
	cout << ans << endl;
		
	return 0;
}
```





[参考](https://blog.csdn.net/y1196645376/article/details/50938608)