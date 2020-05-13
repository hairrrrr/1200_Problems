// 迭代法
// 复杂度：O(n + m)

class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        
        ListNode L1 = l1;
        ListNode L2 = l2;
        ListNode l = new ListNode(0);
        ListNode L = l;

        while(L1 != null && L2 != null){
            if(L1.val > L2.val){
                L.next = L2;
                L2 = L2.next;
            }else{
                L.next = L1;
                L1 = L1.next;
            }
            L = L.next;
        }

        if(L1 == null){
            // 不能写成 L = L2;
            L.next = L2;
        }else{
            L.next = L1;
        }

        return l.next;
    }
}