---
tags: DFS 并查集
---



小蓝要用七段码数码管来表示一种特殊的文字。

![图片描述](https://doc.shiyanlou.com/courses/uid1580206-20210312-1615527941739)

上图给出了七段码数码管的一个图示，数码管中一共有 77 段可以发光的二 极管，分别标记为 `a, b, c, d, e, f, g`。

小蓝要选择一部分二极管（至少要有一个）发光来表达字符。在设计字符 的表达时，要求所有发光的二极管是连成一片的。

例如：`b` 发光，其他二极管不发光可以用来表达一种字符。

例如 `c` 发光，其他二极管不发光可以用来表达一种字符。这种方案与上 一行的方案可以用来表示不同的字符，尽管看上去比较相似。

例如：`a, b, c, d, e` 发光，`f, g` 不发光可以用来表达一种字符。

例如：`b, f` 发光，其他二极管不发光则不能用来表达一种字符，因为发光 的二极管没有连成一片。

请问，小蓝可以用七段码数码管表达多少种不同的字符？



```cpp
#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

const int N = 10, M = 2 * N;

int h[N], e[M], ne[M], idx;
int p[N];
int ans;
bool st[N];

int add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int find(int x)
{
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void dfs(int u)
{
	if(u == 7)
	{
		// 初始化并查集 
		for(int i = 0; i < 7; ++i) p[i] = i;
		
		for(int i = 0; i < 7; ++i) 
		{
			if(st[i])
			{
				// 遍历与 i 相邻的灯  
				for(int j = h[i]; j != -1; j = ne[j])
				{
					int k = e[j];
					// 如果灯 k 也被打开且 j 和 k 不再一个集合中，合并 
					if(st[k] && find(i) != find(k))
						 p[find(i)] = find(k);
				}
			}
		}
		int cnt = 0;
		for(int i = 0; i < 7; ++i)
			if(st[i] && p[i] == i)  
				cnt++;
		if(cnt == 1) ans++;
		
		return;
	}
	
	dfs(u + 1);
	
	st[u] = true;
	dfs(u + 1);
	st[u] = false;
}

int main(void)
{
	memset(h, -1, sizeof h);
	// a b c d e f g
	// 0 1 2 3 4 5 6
	// a 
	add(0, 5), add(0, 1);
	// b
	add(1, 0), add(1, 6), add(1, 2);
	// c
	add(2, 1), add(2, 6), add(2, 3);
	// d
	add(3, 4), add(3, 2);
	// e 
	add(4, 5), add(4, 6), add(4, 3);
	// f
	add(5, 0), add(5, 6), add(5, 4);
	// g
	add(6, 5), add(6, 1), add(6, 4), add(6, 2);
	
//	for(int i = 0; i < 7; ++i)
//	{
//		cout << char(i + 'a') << ": ";
//		for(int j = h[i]; j != -1; j = ne[j])
//		{
//			cout << char(e[j] + 'a') << " ";
//		}
//		cout << endl;
//	}
	
	dfs(0);
	
	cout << ans << endl;
} 
```

