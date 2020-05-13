class Solution {
    public ListNode deleteDuplicates(ListNode head) {

        if(head == null || head.next == null) return head;

        ListNode prev = head;
        ListNode cur = head.next;

        while(cur != null){
            if(cur.val == prev.val){// == 不要写成 = 
                prev.next = cur.next;
                cur = cur.next;
            }else{
                // 这里不要写反
                prev = cur;
                cur = cur.next;
                
            }
        }
        return head;
    }
}