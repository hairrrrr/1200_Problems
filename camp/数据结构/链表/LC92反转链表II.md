---
tags: 链表
---



#### [92 反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/)



给你单链表的头指针 head 和两个整数 left 和 right ，其中 `left <= right` 。请你反转从位置 `left` 到位置 `right` 的链表节点，返回反转后的链表 。

```
示例 1：

输入：head = [1,2,3,4,5], left = 2, right = 4
输出：[1,4,3,2,5]

示例 2：

输入：head = [5], left = 1, right = 1
输出：[5]
```




提示：

```
链表中节点数目为 n
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
```

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(!head || left == right) return head;
        ListNode* dummy  = new ListNode(-1, head);

        // p 是待翻转的链表的开始位置，b 是 p 的前一个位置
        ListNode* b = dummy,  *p = head;
        for(int i = 0; i < left - 1; i++)
            p = p->next, b = b->next;


        ListNode *prev = nullptr, *cur, *nxt = p;

        // 循环结束时 nxt 走到待翻转链表的下一个位置
        for(int i = 0; i < right - left + 1; ++i)
        {
            cur = nxt;
            nxt = nxt->next;
            cur->next = prev;
            prev = cur;
        } 

        p->next = nxt;
        b->next = cur;
        
        return dummy->next;
    }
};
```

