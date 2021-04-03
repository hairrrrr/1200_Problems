---
tags: 链表
---



https://www.acwing.com/problem/content/32/



输入一个链表，输出该链表中倒数第 k 个结点。

**注意：**

- `k >= 1`;
- 如果 k 大于链表长度，则返回 NULL

样例

```
输入：链表：1->2->3->4->5 ，k=2

输出：4
```



```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* findKthToTail(ListNode* head, int k) 
    {
        if(!head) return head;
        
        ListNode *fast = head, *slow = head;
        
        while(fast && k--)
            fast = fast->next;
        // k 大于链表长度
        if(k > 0) return NULL;
        
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        return slow;
    }
};
```

