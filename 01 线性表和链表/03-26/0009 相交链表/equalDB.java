// 双指针的做法等价于：

public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        
        if(headA == null || headB == null) return null;

        ListNode pA = headA;
        ListNode pB = headB;

        // 同时遍历 两个链表
        while(pA != null && pB != null){
            pA = pA.next;
            pB = pB.next;
        }
		
        if(pA == null){
            pA = headB;
        }else{
            pB = headA;
        }
		
        while(pA != null && pB != null){
            pA = pA.next;
            pB = pB.next;
        }

        if(pA == null){
            pA = headB;
        }else{
            pB = headA;
        }

        while(pA != null && pB != null){
            if(pA == pB){
                return pA;
            }
            pA = pA.next;
            pB = pB.next;
        }
        
        return null;
    }
}