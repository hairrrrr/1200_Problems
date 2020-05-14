#### 0025 对链表进行插入排序

https://leetcode-cn.com/problems/insertion-sort-list/

![](https://github.com/hairrrrr/1200_Problems/blob/master/01%20%E7%BA%BF%E6%80%A7%E8%A1%A8%E5%92%8C%E9%93%BE%E8%A1%A8/0025%20%E5%AF%B9%E9%93%BE%E8%A1%A8%E8%BF%9B%E8%A1%8C%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8F/1.gif)

插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

 

插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。


示例 1：

输入: 4->2->1->3
输出: 1->2->3->4

示例 2：

输入: -1->5->3->4->0
输出: -1->0->3->4->5



**C **

解法如图：

![](https://github.com/hairrrrr/1200_Problems/blob/master/01%20%E7%BA%BF%E6%80%A7%E8%A1%A8%E5%92%8C%E9%93%BE%E8%A1%A8/0025%20%E5%AF%B9%E9%93%BE%E8%A1%A8%E8%BF%9B%E8%A1%8C%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8F/11.png)

https://leetcode-cn.com/problems/insertion-sort-list/comments/93262

