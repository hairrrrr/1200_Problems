// 不设置哨兵：
class Solution {
    public ListNode removeElements(ListNode head, int val) {

        if(head == null){
            return null;
        }
        ListNode last = head;
        ListNode cur = last.next;

        while(cur != null){
            if(cur.val == val){
                last.next = cur.next;
            }else{
                last = last.next;
            }
            cur = cur.next;
        }
        if(head.val == val){
            head = head.next;
        }
        return head;
    }
}