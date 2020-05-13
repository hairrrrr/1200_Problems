#### 0013 移除重复节点

OJ 链接：https://leetcode-cn.com/problems/remove-duplicate-node-lcci/

编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

示例1:

 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]

示例2:

 输入：[1, 1, 1, 1, 2]
 输出：[1, 2]

提示：

链表长度在[0, 20000]范围内。
链表元素在[0, 20000]范围内。

进阶：

如果不得使用临时缓冲区，该怎么解决？

**重点：未排序的结点**

**模板**

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
```