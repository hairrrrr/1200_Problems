/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

public class PalindromeList {
    public boolean chkPalindrome(ListNode head) {
        
          if(head == null || head.next == null) {
            return true;
        }

        ListNode fast = head;
        ListNode slow = head;

        // 找到中结点
        while(fast != null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }
        
        // 反转后半部分结点
        ListNode prev = null;
        ListNode cur;
		
        // 链表长为偶数，slow 指向中间偏后的结点，比如【1，2】slow 会指向 2。此时，fast == null
        // 链表长为奇数，slow 指向正中间的结点，此时 fast 指向最后一个结点
        
        if(fast == null){// 链表长度为偶数
            cur = slow;
        }else{
            cur = slow.next;// cur 指向中间结点的下一个
        }
        
        
        while(cur != null){
            ListNode Next  = cur.next;
            cur.next = prev;
            prev = cur;
            cur = Next;
        }

        // prev 为后半部分链表的表头 

        while(prev != null){
            if(prev.val != head.val) {
                return false;
            }
            prev = prev.next;
            head = head.next;
        }
        return true;
    }
}