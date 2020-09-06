[OJ 链接](https://www.nowcoder.com/practice/f0db4c36573d459cae44ac90b90c6212?tpId=85&&tqId=29868&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking)

```cpp
#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    string str1, str2;
 
        // 注意不要用 cin，cin 接受到空格就结束了
        getline(cin, str1);
        getline(cin, str2);
        
        // 将 str2 的元素映射到哈希表中
        int hashTable[256] = {0};
        for(int i = 0; i < str2.size(); i++)
        {
            hashTable[str2[i]] = 1;
        }
        
        string ret;
    	// 将 str2 中没有的字符加到 ret 中
        for(int i = 0; i < str1.size(); i++)
        {
            if(hashTable[str1[i]] == 0)
                ret += str1[i];
        }
        
        cout << ret << endl;
		
    	// 运行超时且 case 通过率为 0 ，可以把用于多测试用例的循环删掉(例如：while(1))
    
    return 0;
}
```

