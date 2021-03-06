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

<b> D </b>

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





#### 16 

以下程序的输出结果是  

```cpp
#include <iostream>
using namespace std;

void func(char** m) {
	++m;
	cout << *m << endl;
} 

int main() {
	static char* a[] = { "morning", "afternoon", "evening" };
	char** p;
	p = a;
	func(p);
	return 0;
}
```

.

```
A afternoon
B 字符o的起始地址
C 字符o
D 字符a的起始地址  
```



<details><summary><b>Answer</b></summary>
<p>

`A`

`++m` m 向后 四个字节，得到指向字符串 `afternoon` 的指针。

`cout << *m << endl` 会输出 `char*` 指针指向的字符串

</p>
</details>



#### 17 有虚函数的类的内存布局

代码执行后，a和b的值分别为?  

```cpp
class Test {
public:
	int a;
	int b;
	virtual void fun() {}
    
	Test(int temp1 = 0, int temp2 = 0)
	{
		a = temp1;
		b = temp2;
	} 
    
    int getA()
	{
		return a;
	} 
    
    int getB()
	{
		return b;
	}
};

int main()
{
	Test obj(5, 10);
	// Changing a and b
	int* pInt = (int*)&obj;
	*(pInt + 0) = 100;
	*(pInt + 1) = 200;
	cout << "a = " << obj.getA() << endl;
	cout << "b = " << obj.getB() << endl;
	return 0;
}
```

```
A 200 10
B 5 10
C 100 200
D 100 10
```



<details><summary><b>Answer</b></summary>
<p>

`A`

</p>
</details>

#### 18 下面哪个指针表达式可以用来引用数组元素`a[i][j][k][l]`

```
A(((a+i)+j)+k)+l)
B *(*(*(*(a+i)+j)+k)+l)
C (((a+i)+j)+k+l)
D ((a+i)+j+k+l)  
```



<details><summary><b>Answer</b></summary>
<p>

`B`

`a` 的类型是 ：`int [i][j][k][l]` 。

但是如果要把 a 看成指针的话，a 的类型是 `int* [j][k][l]`

</p>
</details>



#### 19

```c
int fun(int a){
	a^=(1<<5)-1;
	return a;
}
```

```
A 10
B 5
C 3  
D 8
```





<details><summary><b>Answer</b></summary>
<p>

`A`

```
21:010101

(1<<5):011111

^:001010
```



</p>
</details>





#### 20 计算多维数组元素的地址

二维数组X按行顺序存储，其中每个元素占1个存储单元。若`X[4][4]` 的存储地址为`Oxf8b82140`,`X[9][9]`的存
储地址为`Oxf8b8221c` ,则`X[7][7]` 的存储地址为

```
A Oxf8b821c4
B Oxf8b821a6
C Oxf8b82198
D Oxf8b821c0
```



<details><summary><b>Answer</b></summary>
<p>

`A`

</p>
</details>



#### 21 十进制转二进制

求函数返回值，输入 x=9999

```cpp
int func(int x) {
	int count = 0;
	while (x)
	{
		count++;
		x = x & (x - 1);//与运算
	} 
    return count;
}
```

```
A 8
B 9
C 10
D 12  
```



<details><summary><b>Answer</b></summary>
<p>

`A`

</p>
</details>



#### 22 怎么输出 `%` ?

执行下面语句后的输出为  

```cpp
int I = 1;
if (I <= 0)
	printf("****\n");
else
	printf("%%%%\n");
```

```
A %%
B ****
C 有语法错，不能正确执行
D %%%%
```



<details><summary><b>Answer</b></summary>
<p>

`A`

</p>
</details>



#### 23 基类构造函数调用的虚函数

有如下C++代码：  

```cpp
struct A {
	void foo() { printf("foo"); }
	virtual void bar() { printf("bar"); }
	A() { bar(); }
};
struct B :A {
	void foo() { printf("b_foo"); }
	void bar() { printf("b_bar"); }
};
```

那么：

```cpp
A *p=new B;
p->foo();
p->bar();
```

输出为：

```
A barfoob_bar
B foobarb_bar
C barfoob_foo
D foobarb_fpp
```

<details><summary><b>Answer</b></summary>
<p>

`A`

基类构造调用的虚函数查的是基类的虚函数表

</p>
</details>



#### 24 类成员的初始化顺序

```cpp
class Printer {
public:
	Printer(std::string name) { std::cout << name; }
};
class Container {
public:
	Container() : b("b"), a("a") {}
	Printer a;
	Printer b;
};
int main() {
	Container c;
	return 0;
}
```

```
A 可能是 "ab" 或 "ba"。 依赖于具体的实现
B 一直都是 "ba"
C 一直都是 "ab"
```



<details><summary><b>Answer</b></summary>
<p>

`C`

类成员变量初始化顺序为声明顺序

</p>
</details>



#### 25 默认构造函数

代码可以通过编译吗？如果不能应该如何修改？  

```cpp
template<class T> class Foo {
	T tVar;
public:
	Foo(T t) : tVar(t) { }
};

template<class T> class FooDerived :public Foo<T>
{ };

int main()
{
	FooDerived<int> d(5);
	return 0;
}
```

```
A 代码可以正确通过编译。
B 编译错误，FooDerived是一个继承模板类的非模板类，它的类型不能改变。
C 编译错误，tVal变量是一个不确定的类型。
D 编译错误，可以在FooDerived类中添加一个构造函数解决问题。
```



<details><summary><b>Answer</b></summary>
<p>

`D`

默认构造函数是无参或全缺省的

</p>
</details>



#### 26 前缀一元运算符

在重载一个运算符为成员函数时，其参数表中没有任何参数，这说明该运算符是 （ ）  

```
A 无操作数的运算符
B 二元运算符
C 前缀一元运算符
D 后缀一元运算符  
```



<details><summary><b>Answer</b></summary>
<p>
`C`


</p>
</details>



#### 27

若PAT是一个类，则程序运行时，语句“`PAT(*ad)[3]`;”调用PAT的构造函数的次数是（ ）。  

```
A 2
B 3
C 0
D 1
```



<details><summary><b>Answer</b></summary>
<p>

`C`

</p>
</details>



#### 28

以下程序输出结果是____。

```cpp
class A
{ 
public:
virtual void func(int val = 1)
{ std::cout<<"A->"<<val <<std::endl;}
virtual void test()
{ func();}
};

class B : public A
{ public:
void func(int val=0)  
{std::cout<<"B->"<<val <<std::endl;}
};

int main(int argc ,char* argv[])
{
	B*p = new B;
	p->test();
	return 0;
}
```

```
A A->0
B B->1
C A->1
D B->0
E 编译出错
F 以上都不对
```



<details><summary><b>Answer</b></summary>
<p>

`B`

</p>
</details>



#### 29

下面程序的输出是（）  

```cpp
class A
{
    p
        ublic :
    void foo()
    {
        printf("1");
    } v
        irtual void fun()
    {
        printf("2");
    }
};
class B : public A
{
    p
        ublic :
    void foo()
    {
        printf("3");
    } v
        oid fun()
    {
        printf("4");
    }
};

int main(void)
{
    A a;
	B b;
	A* p = &a;
	p->foo();
	p->fun();
	p = &b;
	p->foo();
	p->fun();
	A* ptr = (A*)&b;
	ptr->foo();
	ptr->fun();
    
	return 0;
}
```

```
A 121434
B 121414
C 121232
D 123434  
```



<details><summary><b>Answer</b></summary>
<p>

`B`

</p>
</details>



#### 30 

下面程序的输出结果是？  

```cpp
#include<iostream.h>
void main() {
    int n[][3] = { 10,20,30,40,50,60 };
    int(*p)[3];
    p = n;
    cout << p[0][0] << "," << *(p[0] + 1) << "," << (*p)[2] << endl;
}
```

```
A 10,30,60
B 10,30,50
C 10,20,30
D 20,40,60
```



<details><summary><b>Answer</b></summary>
<p>
`C`

</p>
</details>



#### 31 

下面程序的输出结果是_______。  

```cpp
#include < iostream.h>
#define SQR(A) A*A
void main() {
    int x = 6, y = 3, z = 2;
    x /= SQR(y + z) / SQR(y + z);
    cout < < x < < endl;
}
```

```
A 5
B 6
C 1
D 0
```



<details><summary><b>Answer</b></summary>
<p>

`D`

</p>
</details>



#### 32 内存对齐

在一个64位的操作系统中定义如下结构体  

```cpp
struct st_task
{
    uint16_t id;
    uint32_t value;
    uint64_t timestamp;
};
void fool()
{
    st_task task = {};
    uint64_t a = 0x00010001;
    memcpy(&task, &a, sizeof(uint64_t));
    printf("%11u,%11u,%11u", task.id, task.value, task.timestamp);
}
```

上述`fool()`程序的执行结果为（）  

```
A 1，0，0
B 1，1，0
C 0，1，1
D 0，0，1
```



<details><summary><b>Answer</b></summary>
<p>

`A`

一般机器都是小端存储

```
id（两个字节） -> 01 00
pad（内存对齐，两个字节） -> 01 00
value（四个字节） -> 00 00 00 00 （a 的表示中省略了高位 4 个字节的 0）
```



</p>
</details>



#### 33 

下列一段C++代码的输出是?  

```cpp
#include "stdio.h"
class Base
{
    public :
    int Bar(char x)
    {
        return (int)(x);
    } 
    virtual int Bar(int x)
    {
        return (2 * x);
    }
};
class Derived : public Base
{
    public :
    int Bar(char x)
    {
        return (int)(-x);
    } 
    int Bar(int x)
    {
        return (x / 2);
    }
};
int main(void)
{
    Derived Obj;
    Base* pObj = &Obj;
    printf("%d,", pObj->Bar((char)(100)));
    printf("%d,", pObj->Bar(100));
}
```

```
A 100，-100
B 100，50
C 200，-100
D 200，50
```





<details><summary><b>Answer</b></summary>
<p>

`B`

要理解 C++ 函数重载的机制，重载的函数底层的函数名是不同的，可以理解为不同的函数。

</p>
</details>



#### 34 在嵌套使用if语句时，C语言规定else总是___  

```
A 和之前与其具有相同缩进位置的if配对
B 和之前与其最近的if配对
C 和之前与其最近的且不带else的if配对
D 和之前的第一个if配对
```





<details><summary><b>Answer</b></summary>
<p>
`C`

</p>
</details>



#### 35 以下程序的输出结果是__。  

```cpp
#include <stdio.h>
int main()
{
    int i, a[10];
    for (i = 9; i >= 0; i--) a[i] = 10 - i;
    printf("%d%d%d", a[2], a[5], a[8]);
    return 0;
}
```
```
A 258
B 741
C 852
D 369
```

<details><summary><b>Answer</b></summary>
<p>
`C`

</p>
</details>



#### 36 

下面C程序的输出结果  

```cpp
int i=0,a=1,b=2,c=3;
i=++a||++b||++c;
printf("%d %d %d %d",i,a,b,c);
```

```
A 1 2 2 3
B 1 2 3 4
C 3 2 3 4
D 3 3 3 4
```



<details><summary><b>Answer</b></summary>
<p>

  `A`

</p>
</details>



#### 37 

```c
using namespace std;

#include<stdio.h>
struct str_t {
	long long len;
	char data[32];
};
struct data1_t {
	long long len;
	int data[2];
};
struct data2_t {
	long long len;
	char* data[1];
};
struct data3_t {
	long long len;
	void* data[];
};
int main(void)
{
struct str_t str;
memset((void*)&str,0,sizeof(struct str_t));
str.len=sizeof(struct str_t)-sizeof(int);
snprintf(str.data,str.len,"hello");//VS下为_snprintf
____________________________________;
____________________________________;
return 0;
}
```

```
A struct data3_t *pData=(struct data3_t*)&str; printf("data:%s%s\n",str.data,(char*)(&(pData->data[0])));
B struct data2_t *pData=(struct data2_t*)&str; printf("data:%s%s\n",str.data,(char*)(pData->data[0]));
C struct data1_t *pData=(struct data1_t*)&str;printf("data:%s%s\n",str.data,(char*)(pData->data));
D struct str_t *pData=(struct str_t*)&str; printf("data:%s%s\n",str.data,(char*)(pData->data));
```



<details><summary><b>Answer</b></summary>
<p>

`B`

```c
#include<iostream>
#include<vector>
#include<string>

using namespace std;

#include<stdio.h>
struct str_t {
	long long len;
	char data[32];
};
struct data1_t {
	long long len;
	int data[2];
};
struct data2_t {
	long long len;
	char* data[1];
};
struct data3_t {
	long long len;
	void* data[];
};
int main(void)
{
	struct str_t str;
	memset((void*)&str, 0, sizeof(struct str_t));
	str.len = sizeof(struct str_t) - sizeof(int);
	snprintf(str.data, str.len, "hello");//VS下为_snprintf
	
	// OK
	//struct data3_t* pData = (struct data3_t*)&str;
	//printf("data:%s%s\n", str.data, (char*)(&(pData->data[0])));

	// Wrong 
	// pData->data[0] 拿到的是 str 中 data 字段的第一个字符
	struct data2_t* pData = (struct data2_t*)&str; 
	printf("data:%s%s\n", str.data, (char*)(pData->data[0]));
	
	

	// OK
	//struct data1_t* pData = (struct data1_t*)&str;
	//printf("data:%s%s\n", str.data, (char*)(pData->data));

	return 0;
}
```



</p>
</details>





#### 38 哪个操作符不能被重载?  

```
A , (逗号)
B ()
C . (点)
D []
E ->
```





<details><summary><b>Answer</b></summary>
<p>

  `C`

</p>
</details>



#### 39 下列关于多态性说法不正确的是

```
A 多态性是指同名函数对应多种不同的实现
B 重载方式仅有函数重载
C 重载方式包含函数重载和运算符重载
D 多态性表现为静态和动态两种方式
```

<details><summary><b>Answer</b></summary>
<p>

 `B`

</p>
</details>



#### 40

```cpp
#include<iostream>
using namespace std;
class B
{
public :
	B()
	{
		cout << "default constructor" << " ";
	} 
	
	~B()
	{
		cout << "destructed" << " ";
	} 

	B (int i) : data(i)
	{
		cout << "constructed by parameter" << data << " ";
	} 
	private : int data;
};

B Play(B b)
{
	return b;
} 

int main(int argc, char* argv[])
{
	B temp = Play(5);
	return 0;
}
```

```
A constructed by parameter5 destructed destructed
B constructed by parameter5 destructed
C default constructor" constructed by parameter5 destructed
D default constructor" constructed by parameter5 destructed destructed
```

<details><summary><b>Answer</b></summary>
<p>

 `A  `

</p>
</details>



#### 41 

求输出结果  

```cpp
#include <iostream>
using namespace std;
class A
{
public :
	virtual void print()
	{
		cout << "A::print()" << "\n";
	}
};

class B : public A
{
public: virtual void print()
{
	cout << "B::print()" << "\n";
}
};
class C : public A
{
	public : virtual void print()
	{
		cout << "C::print()" << "\n";
	}
};

void print(A a)
{
	a.print();
} 

int main()
{
	A a, * aa, * ab, * ac;
	B b;
	C c;
	aa = &a;
	ab = &b;
	ac = &c;
	a.print();
	b.print();
	c.print();
	aa->print();
	ab->print();
	ac->print();
	print(a);
	print(b);
	print(c);
}
```

```
A C::print() B::print() A::print() A::print() B::print() C::print() A::print() A::print() A::print()
B A::print() B::print() C::print() A::print() B::print() C::print() A::print() A::print() A::print()
C A::print() B::print() C::print() A::print() B::print() C::print() B::print() B::print() B::print()
D C::print() B::print() A::print() A::print() B::print() C::print() C::print() C::print() C::print()
```



<details><summary><b>Answer</b></summary>
<p>

 `B`

</p>
</details>



#### 42 假设寄存器为8位，用补码形式存储机器数，包括一位符号位，那么十进制数`-25`在寄存器表示为  

```
A 67H
B 99H
C E6H
D E7H  
```



<details><summary><b>Answer</b></summary>
<p>
`D`

```
-1 -> FF
-1 - 24 = -25
FF - 18 = E7
```



</p>
</details>



#### 43 

```cpp

int Function(unsigned int n) {
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
    return n;
}
```

输入参数为197时，函数返回多少？  

```
A 2
B 3
C 4
D 5
```



<details><summary><b>Answer</b></summary>
<p>

`C`

这是“平行算法”求二进制位中 1 的个数。

可以参考：

https://blog.csdn.net/hyqsong/article/details/50880526

https://www.nowcoder.com/questionTerminal/618c7143cc664cd4afe8ddb2ccaab2cf

</p>
</details>



#### 44 下面程序的功能是输出数组的全排列。请填空  

```cpp
void perm(int list[], int k, int m)
{
    if ()
    {
        copy(list, list + m, ostream_iterator<int>(cout, " "));
        cout << endl;
        return;
    } 
    for (int i = k; i <= m; i++)
    {
        swap(&list[k], &list[i]);
        ();
        swap(&list[k], &list[i]);
    }
}
```

```
A k!=m 和 perm（list，k+1，m）
B k==m 和 perm（list，k+1，m）
C k!=m 和 perm（list，k，m）
D k==m 和 perm（list，k，m）
```



<details><summary><b>Answer</b></summary>
<p>

`B`

</p>
</details>



#### 45 const 和 mutable

以下代码编译有错误，哪个选项能解决编译错误？  

```cpp
class A {
public:
    int GetValue() const {
        vv = 1;
        return vv;
    }
private:
    int vv;
};
```

```
A 改变成员变量"vv"为"mutable int vv"
B 改变成员函数"GetValue"的声明，以使其不是const的
C 都不能修复编译错误
D 都可以修复编译错误
```



<details><summary><b>Answer</b></summary>
<p>

`D`

</p>
</details>

#### 46

以下程序的输出是  

```cpp
class Base {
public:
    Base(int j) : i(j) {}
    virtual~Base() {}
    void func1() {
        i *= 10;
        func2();
    } 
    int getValue() {
        return i;
    } 
    protected :
    virtual void func2() {
        i++;
    } 
    protected :
    int i;
};
class Child : public Base {
public:
    Child(int j) : Base(j) {}
    void func1() {
        i *= 100;
        func2();
    } 
    protected :
    void func2() {
        i += 2;
    }
};
int main() {
    Base* pb = new Child(1);
    pb->func1();
    cout << pb->getValue() << endl; delete pb;
}
```



<details><summary><b>Answer</b></summary>
<p>

`C`

</p>
</details>



#### 47 静态联编和动态联编 

调用一成员函数时, 使用动态联编的情况是  

```
A 通过对象调用一虚函数
B 通过指针或引用调用一虚函数
C 通过对象调用静态函数
D 通过指针或应用调用一静态函数
```



<details><summary><b>Answer</b></summary>
<p>
`B`

静态联编：

```cpp
#include <iostream>
using namespace std;
class shape {
public:
    void draw() { cout << "I am shape" << endl; }
    void fun() { draw(); }
};
class circle :public shape {
public:
    void draw() { cout << "I am circle" << endl; }
};
void main() {
    circle  oneshape;
    oneshape.fun();
}
```

使用 VS 反汇编查看：

```
 void fun() { draw(); }
00EE2560  push        ebp  
00EE2561  mov         ebp,esp  
00EE2563  sub         esp,0CCh  
00EE2569  push        ebx  
00EE256A  push        esi  
00EE256B  push        edi  
00EE256C  push        ecx  
00EE256D  lea         edi,[ebp-0CCh]  
00EE2573  mov         ecx,33h  
00EE2578  mov         eax,0CCCCCCCCh  
00EE257D  rep stos    dword ptr es:[edi]  
00EE257F  pop         ecx  
00EE2580  mov         dword ptr [this],ecx  
00EE2583  mov         ecx,0EEF027h  
00EE2588  call        @__CheckForDebuggerJustMyCode@4 (0EE1294h)  
00EE258D  mov         ecx,dword ptr [this]  
00EE2590  call        shape::draw (0EE1442h)   !!!! 注意这句话 ！！！！
00EE2595  pop         edi  
00EE2596  pop         esi  
00EE2597  pop         ebx  
00EE2598  add         esp,0CCh  
00EE259E  cmp         ebp,esp  
00EE25A0  call        __RTC_CheckEsp (0EE129Eh)  
00EE25A5  mov         esp,ebp  
00EE25A7  pop         ebp  
00EE25A8  ret  
```

动态联编：

```cpp
#include <iostream>
using namespace std;
class shape {
public:
    void virtual draw() { cout << "I am shape" << endl; }//这里设定了draw是虚函数
    void fun() { draw(); }
};
class circle :public shape {
public:
    void draw() { cout << "I am circle" << endl; }//虽然没有说明circle类中的draw是虚函数，但是circle其实继承了virtual性质
};
void main() {
    circle  oneshape;
    oneshape.fun();
}
```

反汇编：

```
void fun() { draw(); }
00952740  push        ebp  
00952741  mov         ebp,esp  
00952743  sub         esp,0CCh  
00952749  push        ebx  
0095274A  push        esi  
0095274B  push        edi  
0095274C  push        ecx  
0095274D  lea         edi,[ebp-0CCh]  
00952753  mov         ecx,33h  
00952758  mov         eax,0CCCCCCCCh  
0095275D  rep stos    dword ptr es:[edi]  
0095275F  pop         ecx  
00952760  mov         dword ptr [this],ecx  
00952763  mov         ecx,offset _24CB8158_testJieba@cpp (095F027h)  
00952768  call        @__CheckForDebuggerJustMyCode@4 (0951294h)  
0095276D  mov         eax,dword ptr [this]  
00952770  mov         edx,dword ptr [eax]  
00952772  mov         esi,esp  
00952774  mov         ecx,dword ptr [this]  
00952777  mov         eax,dword ptr [edx]  
00952779  call        eax   ！！！ 这里应该是查找虚函数表 ！！！
0095277B  cmp         esi,esp  
0095277D  call        __RTC_CheckEsp (095129Eh)  
00952782  pop         edi  
00952783  pop         esi  
00952784  pop         ebx  
00952785  add         esp,0CCh  
0095278B  cmp         ebp,esp  
0095278D  call        __RTC_CheckEsp (095129Eh)  
00952792  mov         esp,ebp  
```



[参考文章](https://blog.csdn.net/gaoxin1076/article/details/8298279)

</p>
</details>



#### 48 异常的捕获方式

如何捕获异常可以使得代码通过编译？  

```cpp
class A {
public:
    A() {}
};
void foo() {
    throw new A;
}
```

```
A catch (A && x)
B catch (A * x)
C catch (A & x)
D 以上都是
```



<details><summary><b>Answer</b></summary>
<p>
`B`


</p>
</details>



#### 49 *

假设在一个 32 位 `little endian` 的机器上运行下面的程序，结果是多少？  



```cpp
#include <stdio.h>
int main() {
    long long a = 1, b = 2, c = 3;
    printf("%d %d %d\n", a, b, c);
    return 0;
}
```

```
A 1,2,3
B 1,0,2
C 1,3,2
D 3,2,1
```



<details><summary><b>Answer</b></summary>
<p>

`B`

[参考文章](https://www.cnblogs.com/dingou/p/5834186.html)

</p>
</details>



#### 50 

```cpp
class A {
public:
    A() { p(); }
    virtual void p() { print("A") }
    virtual ~A() { p(); }
};
class B :public A {
public:
    B() { p(); }
    void p() { print("B") }
    ~B() { p(); }
};
int main(int, char**) {
    A* a = new B();
    delete a;
}
```

```
A AABB
B BBAA
C ABAB
D ABBA
```





<details><summary><b>Answer</b></summary>
<p>

`D  `

</p>
</details>