#### 0029 设计循环队列

https://leetcode-cn.com/problems/design-circular-queue/

设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

你的实现应该支持如下操作：

```
MyCircularQueue(k): 构造器，设置队列长度为 k 。
Front: 从队首获取元素。如果队列为空，返回 -1 。
Rear: 获取队尾元素。如果队列为空，返回 -1 。
enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
isEmpty(): 检查循环队列是否为空。
isFull(): 检查循环队列是否已满。
```


示例：

```
MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3

circularQueue.enQueue(1);  // 返回 true

circularQueue.enQueue(2);  // 返回 true

circularQueue.enQueue(3);  // 返回 true

circularQueue.enQueue(4);  // 返回 false，队列已满

circularQueue.Rear();  // 返回 3

circularQueue.isFull();  // 返回 true

circularQueue.deQueue();  // 返回 true

circularQueue.enQueue(4);  // 返回 true

circularQueue.Rear();  // 返回 4
```

提示：

所有的值都在 0 至 1000 的范围内；
操作数将在 1 至 1000 的范围内；
请不要使用内置的队列库。

![](https://github.com/hairrrrr/1200_Problems/blob/master/02%20%E6%A0%88%E5%92%8C%E9%98%9F%E5%88%97/0029%20%E8%AE%BE%E8%AE%A1%E5%BE%AA%E7%8E%AF%E9%98%9F%E5%88%97/14.png)

循环队列是满还是空的判断方法其实值得我们思考：

- 如果存放循环队列的数组每个元素都可以是队列的一部分，那么我们需要提供一个变量来记录队列的大小。
- 如果我们不想使用变量来记录队列的大小，我们需要让数组的一个元素始终不属于队列。那么队列为空时：`front == rear`；队列为满时：`(rear + 1) % k(数组大小) == front`

如何理解第二种情况的公式呢？

![](https://github.com/hairrrrr/1200_Problems/blob/master/02%20%E6%A0%88%E5%92%8C%E9%98%9F%E5%88%97/0029%20%E8%AE%BE%E8%AE%A1%E5%BE%AA%E7%8E%AF%E9%98%9F%E5%88%97/15.png)

如图第一种情况：这种情况比较普通，这时候其实不用模数组的大小，只要 `rear + 1 == front`即可判满

第二种情况：rear + 1 会越界，这时候我们才需要对数组大小求模

为了方便起见，我们直接对数组大小求模即可。

**C**
第一种方法：myCircularQueue
第二种方法：**myCircularQueue2