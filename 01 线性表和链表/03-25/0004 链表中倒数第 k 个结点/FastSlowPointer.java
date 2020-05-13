public class Solution {
    public ListNode FindKthToTail(ListNode head,int k) {
       
        // k 必须是大于 0 的（倒数第 0 个数 没听说过把 -_-）
        if(head == null || k <= 0){
            return null;
        }
        
        ListNode fast = head;
        ListNode slow = head;
        
        // 快指针先走 k - 1  步
        while((fast != null) && (k - 1 > 0)){
            k--;
            fast = fast.next;
            
            // k 的取值范围是 1 ~ len(链表长度)
            // 所以 fast 走的步数就是 0 ~ len - 1
            // 当 fast == null 时，fast 走了 len 步
            // 正常情况下，所以 fast 是不能等于 null 的
            if(fast == null){
                return null;
            }
        }
        
        // 当 快指针为 null 时，slow 走到到数第 k 个结点
         while(fast.next != null){
             fast = fast.next;
             slow = slow.next;
         }
        
        return slow;
    }
}