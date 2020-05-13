//**哨兵法（强推）**

//应用哨兵就不需要去想奇偶的问题了。

//0003 题中，如果有两个中间结点，返回第二个，这种方法可以实现返回第一个。（奇数情况不变。）

class Solution {
    public boolean isPalindrome(ListNode head) {
        
       if(head == null || head.next == null) {
            return true;
        }
        // 创建一哨兵结点，
        ListNode sentinel = new ListNode(-1);
        sentinel.next = head;
        ListNode fast = sentinel;
        ListNode slow = sentinel;

        // 找到中结点
        while(fast != null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }
        
        // 反转后半部分结点
        ListNode prev = null;
        ListNode cur = slow.next;
		

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