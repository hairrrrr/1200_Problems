public class Solution {
    public boolean hasCycle(ListNode head) {
        
        ListNode slow = head;
        ListNode fast = head;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            // 如果 fast == slow 说明是环形链表
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
}