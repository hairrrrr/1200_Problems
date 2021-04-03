---
tags: 链表
---



#### [82. 删除排序链表中的重复元素 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/)



存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。

返回同样按升序排列的结果链表。

 ```
示例 1：

输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]

示例 2：

输入：head = [1,1,1,2,3]
输出：[2,3]
 ```


提示：

```
链表中节点数目在范围 [0, 300] 内
-100 <= Node.val <= 100
题目数据保证链表已经按升序排列
```



```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(!head) return head;
        ListNode* dummy = new ListNode(-1, head), *prev = dummy, *cur = head;
        while(cur)
        {
            // 如果 prev 下一个结点的值和 cur 相同
            while(cur && prev->next->val == cur->val) cur = cur->next;
            // 没有重复，prev 和 cur 中间只隔着 1 个结点
            if(prev->next->next == cur) prev = prev->next;
            // 存在重复，prev 不移动，但是将 prev 的next 更新成 cur
            else prev->next = cur;
        }
        return dummy->next;
    }
};
```

