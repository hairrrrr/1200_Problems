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

 

#### 08 

对于下面的C语言声明描述正确的一项是（）
`char (*p)[16]  `

```
A p是长度为16的字符指针数组
B p是包含16个字符的字符串
C p是指向长度为16的字符数组的指针
D p是长度为16的字符数组  
```

`C`

`(*p)` 表示 p 是一个指针，`[16]` 表示 p 指向的是一个大小为 16 的数组，`char` 表示这个数组每个元素是 `char` 类型。



#### 09

以下程序运行时，若输入 `1abcedf2df<回车>` 输出结果是？

```c
#include<stdio.h>
int main()
{
	char a = 0, ch;
	while((ch=getchar())!='\n')
	{
		if(a%2!=0&&(ch >= 'a' && ch <= 'z'))
		ch = ch - 'a' + 'A';
		a++;
		putchar(ch);
	} 
	printf( "\n");
}  
```

```
A 1abcedf2df
B 1ABCEDF2DF
C 1AbCeDf2dF
D 1abceDF2DF  
```

`C`



#### 10 二维数组初始化

在`int p[][4]={{1},{3,2},{4,5,6},{0}};`中，`p[1][2]` 的值是()  

A 1
B 0
C 6
D 2  

`B`

对于二维数组的初始化还要注意以下几点：

1) 可以只对部分元素赋值，未赋值的元素自动取“零”值。例如：

```
int a[3][3] = {{1}, {2}, {3}};
```

是对每一行的第一列元素赋值，未赋值的元素的值为 0。赋值后各元素的值为：
1  0  0
2  0  0
3  0  0

再如：

```
int a[3][3] = {{0,1}, {0,0,2}, {3}};
```

赋值后各元素的值为：
0  1  0
0  0  2
3  0  0

[引用](http://c.biancheng.net/view/1829.html)



#### 11 && 和 || 的短路原则

```c
#include <stdio.h>
int main()
{
	int a = 1, b = 2, c = 3, d = 0;
	if (a == 1 && b++ == 2)
		if (b != 2 || c-- != 3)
			printf("%d,%d,%d\n", a, b, c);
		else
			printf("%d,%d,%d\n", a, b, c);
	else
		printf("%d,%d,%d\n", a, b, c);
	return 0;
}
```

下面程序输出是什么？  

A 1，2，3
B 1，3，2
C 3，2，1
D 1，3，3  

`D`



#### 12 &数组名的地址

下面代码会输出()

```c
int main()
{
	int a[4]={1,2,3,4};
	int *ptr=(int*)(&a+1);
	printf("%d",*(ptr-1));
}  
```

A 4
B 1
C 2
D 3  



<details><summary><b>Answer</b></summary>
<p>
##### D

`&a` 的类型是 `int* [4]` 

</p>
</details>



#### 13 在公有派生的情况下，派生类中定义的成员函数只能访问原基类的

```
A 公有成员和私有成员
B 私有成员和保护成员  
C 公有成员和保护成员
D 私有成员,保护成员和公有成员  
```



<details><summary><b>Answer</b></summary>
<p>

`C`

</p>
</details>



#### 14 类类型的数组元素会执行构造函数吗？

假定有类AB，有相应的构造函数定义，能正确执行

`AB a(4),b(5),c[3],*p[2]={&a,&b};`

语句，请问执行完此语句后共调用该类的构造函数次数为___  

```
A 5
B 4
C 3
D 9  
```





<details><summary><b>Answer</b></summary>
<p>

`A`

</p>
</details>



#### 15 关于多态

```cpp
class A
{
public:
	A() :m_iVal(0) { test(); }
	virtual void func() { std::cout << m_iVal << ‘ ’; }
	void test() { func(); }
public:
	int m_iVal;
};
class B : public A
{
public:
	B() { test(); }
	virtual void func()
	{
		++m_iVal;
		std::cout << m_iVal << ‘ ’;
	}
};
int main(int argc, char* argv[])
{
	A* p = new B;
	p->test();
	return 0;
}
```

```
A 1 0
B 0 1
C 0 1 2
D 2 1 0
E 不可预期
F 以上都不对  
```

<details><summary><b>Answer</b></summary>
<p>

`C`

</p>
</details>





<details><summary><b>Answer</b></summary>
<p>



</p>
</details>


