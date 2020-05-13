// 或者我们处理 反转链表——原链表长度为奇数时，反转链表带上中间元素，那么判空的指标就应该是 head

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
        ListNode cur = slow;		
        
        
        while(cur != null){
            ListNode Next  = cur.next;
            cur.next = prev;
            prev = cur;
            cur = Next;
        }

        // 用 head.next 作为结束指标
        // 这是因为 原链表长度为奇数时，假设为【1，2，3，4，5】，链表被分为【1，2】【3，4，5】两部分
		// 后半部分比较长，所以应该用前面的先判断，但是当 head = null 时，head 已经指向 3 了（第二个结点的指针域还是指向第三个结点的），所以得用 head.next 来判断
        // 而如果你用 prev.next 的话，当原链表长度为偶数时，两个链表的最后一个结点是不能被比较的
        while(head.next != null){
            if(prev.val != head.val) {
                return false;
            }
            prev = prev.next;
            head = head.next;
        }
        return true;
    }
}