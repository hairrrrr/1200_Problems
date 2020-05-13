public class Partition {
    //设置两个链表头，遍历原链表，一个追加小数链表，一个追加大数链表，最后将小数链表粘到大数链表前边即为结果。（引自牛客网coder： 念闰）
    
    public ListNode partition(ListNode pHead, int x) {
        
        if(pHead == null){
            return null;
        }
        
        ListNode smaller = new ListNode(-1);
        ListNode  bigger = new ListNode(-1);
        ListNode cur = pHead, pS = smaller, pB = bigger;
        
        while(cur != null){
            if(cur.val < x){
                pS.next = cur;
                pS = pS.next;
            }else{
                pB.next = cur;
                pB = pB.next;
            }
            cur = cur.next;
        }
        // 一定要将最后的节点的指针域置为 null ！！！
        pB.next = null;
        // 将 smaller 链表最后一个节点的指针域放置 bigger 链表的头指针
        pS.next = bigger.next;
        
        // 返回头指针
        return smaller.next;
    }
}