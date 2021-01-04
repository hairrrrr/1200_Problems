定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

 

示例:

```
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
```


提示：

各函数的调用总次数不超过 20000 次

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

[题解](https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/solution/mian-shi-ti-30-bao-han-minhan-shu-de-zhan-fu-zhu-z/)

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() 
    {

    }
    
    void push(int x) 
    {
        S.push(x);
        if(minS.empty() || minS.top() >= x)
            minS.push(x);
    }
    
    void pop() 
    {
        if(S.top() == minS.top())
            minS.pop();
        S.pop();
    }
    
    int top() 
    {
        return S.top();
    }
    
    int min() 
    {
        return minS.top();
    }
private:
    stack<int> S;
    stack<int> minS;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
```

