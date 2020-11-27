> 不注意细节的程序员不是好的程序员。
>
> ​															——鲁迅

#### 01

```c
#include<stdio.h>

int main(void)
{
	const char* str = "computer";

	printf("%s,%5.3s", str, str);

	//输出结果为？

	return 0;
}

答案：
computer, com
解析：
前两个都是s格式符，用来输出字符串。
% m.ns 输出占m列，但只取字符串中左端n个字符。这n个字符输出在m列的右侧，左补空格。
```

[参考资料](https://blog.csdn.net/xueruifan/article/details/46128773)



#### 02 在（）情况下适宜采用 inline 定义内联函数 

```
A 函数体含有循环语句 
B 函数体含有递归语句 
C 函数代码少、频繁调用 
D 函数代码多，不常调用 
```

正确答案：C 



#### 03 int *p[4] 与选择项中的 说明 （） 等价 :

```
 A int p[4] 
 B int *p 
 C int *(p[4]) 
 D int (*p)[4]
```

正确答案：C 



#### 04

下面叙述不正确的是（） 

```c
A 派生类一般都用公有派生 
B 对基类成员的访问必须是无二义性的 
C 赋值兼容规则也适用于多重继承的组合 
D 父类的公有成员在派生类中仍然是公有的 
```

正确答案：D 

![](https://hairrrrr.github.io/assets/2020-11-27-3.png)



#### 05 当一个类对象的生命周期结束后，关于调用析构函数的描述正确的是:（）

```
A 如果派生类没有定义析构函数，则只调用基类的析构函数
B 如果基类没有定义析构函数，则只调用派生类的析构函数
C 先调用派生类的析构函数，后调用基类的析构函数
D 先调用基类的析构函数，后调用派生类的析构函数  
```

```answer
C
```



#### 06 下面关于一个类的静态成员描述中,不正确的是()  

```
A 静态成员变量可被该类的所有方法访问
B 该类的静态方法只能访问该类的静态成员函数
C 该类的静态数据成员变量的值不可修改
D 子类可以访问父类的静态成员
E 静态成员无多态特性
```

C

**静态成员无多态特性** 

- 使用多态时至少要有父类，子类对象。静态函数与对象无关
- `static` 成员函数语法上不能被设置为 `virtual`



#### 07 

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	vector<int>array;
	array.push_back(100);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(500);
	vector<int>::iterator itor;
	for (itor = array.begin(); itor != array.end(); itor++)
	{
		if (*itor == 300)
		{
			itor = array.erase(itor);
		}
	} 
	for (itor = array.begin(); itor != array.end(); itor++)
	{
		cout << *itor << " ";
	}
	return 0;
}
```

答案：

```
A 100 300 300 300 300 500
B 100 3OO 300 300 500
C 100 300 300 500
D 100 300 500
E 100 500
F 程序错误
```

C

重点在 `itor = array.erase(itor);` 

`erase` 会返回被删除的元素的后一个元素的指针。在 `itor++` 时会跳过一个元素

 