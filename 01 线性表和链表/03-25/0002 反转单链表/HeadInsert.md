// 头插法
// 思路是：cur = head.next 让 cur 从第二个结点开始遍历链表，如果 cur.next 不是 null，那么将这个结点头插（作为新的表头）
class Solution {
    public ListNode reverseList(ListNode head) {
        
        if(head == null || head.next == null){
            return head;
        }         
        ListNode cur = head.next;
        ListNode Next = null;
        // 头结点指针域置为 null
        head.next = null;

        while(cur != null){
            
            Next = cur.next;// 记录当前结点下一个结点
            cur.next = head;// 头插
            head = cur; // 将当前结点作为新的表头
            cur = Next;   
        }

        return head;

    }
}