// 快慢指针法
//我们可以继续优化方法二，用两个指针 slow 与 fast 一起遍历链表。slow 一次走一步，fast 一次走两步。那么当 fast 到达链表的末尾时，slow 必然位于中间。
//时间复杂度：O(n)
//空间复杂度：O(1)

class Solution {
    public ListNode middleNode(ListNode head) {
        
       ListNode fast = head;
       ListNode slow = head;

       while(fast != null && fast.next != null){
           slow = slow.next;
           fast = fast.next.next;
       }
       return slow; 
    }
}
