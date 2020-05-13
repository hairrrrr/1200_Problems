#### 0009 相交链表

OJ链接：https://leetcode-cn.com/problems/intersectionof-two-linked-lists/description/  

题目描述：

![](https://github.com/hairrrrr/1200_Problems/blob/master/img/1.PNG)

![](https://github.com/hairrrrr/1200_Problems/blob/master/img/2.PNG)

##### 反思

这道题其实很简单的。这题目的输入输出写了一大堆其实没必要看太仔细。注意题目描述部分 和 给你的模板中的函数特征（返回类型，参数）。其实就是一个快指针会不会和慢指针相等的问题。

**暴力法**

像冒泡排序那样两层 for 循环遍历，找到退出即可，时间复杂度为：O(m*n)

**模板**

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
```