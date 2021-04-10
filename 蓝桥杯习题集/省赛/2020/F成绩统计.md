 题目描述

小蓝给学生们组织了一场考试，卷面总分为 100 分，每个学生的得分都是一个 0 到 100 的整数。

如果得分至少是 60 分，则称为及格。如果得分至少为 85 分，则称为优秀。

请计算及格率和优秀率，用百分数表示，百分号前的部分四舍五入保留整 数。

### 输入描述

输入的第一行包含一个整数 n (1≤*n*≤10^4)，表示考试人数。

接下来 n 行，每行包含一个 0 至 100 的整数，表示一个学生的得分。

### 输出描述

输出两行，每行一个百分数，分别表示及格率和优秀率。百分号前的部分 四舍五入保留整数。

### 输入输出样例

#### 示例

> 输入

```txt
7
80
92
56
74
88
100
0
```

> 输出

```txt
71%
43%
```



```cpp

#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	int pass = 0, excl = 0;
	for(int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		if(x >= 60) pass++;
		if(x >= 85) excl++;
	} 
	
    // 小数点后三位四舍五入
	int a = ((double)pass / n + 0.005) * 100;
	int b = ((double)excl / n + 0.005) * 100;
	
	
	
	printf("%d%%\n%d%%", a, b);
	
	return 0;
} 
```

