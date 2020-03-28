// 时间复杂度：O(n)

// 空间复杂度：O(1)

class Solution {
    public ListNode middleNode(ListNode head) {
        
        ListNode cur = head;

        // 先遍历一遍链表算出链表长度
        int len = 0;
        while(cur != null){
            len++;
            cur = cur.next;
        }

        // 再遍历一遍，输出 len / 2 号元素
        cur = head;
        int i = 1;
        while(i < len / 2 + 1){
            cur = cur.next;
            i++;
        }
        
        return cur; 
    }
}