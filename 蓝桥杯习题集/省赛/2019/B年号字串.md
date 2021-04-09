---
tags: 进制转换
---



小明用字母 A 对应数字 1，B 对应 2，以此类推，用 Z 对应 26。对于 27 以上的数字，小明用两位或更长位的字符串来对应，例如 AA 对应 27，AB 对应 28，AZ 对应 52，LQ 对应 329。

请问 2019对应的字符串是什么？



#### 递归

```cpp
#include <iostream>

using namespace std;

string ans;

void dfs(int n)
{
	if(!n) return;
	dfs(n / 26);
	ans += (n % 26 + 'A' - 1);
}

int main()
{
	dfs(2019);  
  	
  	cout << ans << endl;

	return 0;
}
```



#### 非递归

```cpp
#include <iostream>

using namespace std;

string ans;

int main()
{
	int n = 2019;
	while(n)
	{
		char ch = n % 26 + 'A' - 1;
		ans = ch + ans;
		n /= 26;
	}
  	
  	cout << ans << endl;

	return 0;
}
```

