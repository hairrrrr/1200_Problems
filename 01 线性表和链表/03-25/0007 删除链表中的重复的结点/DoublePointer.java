/*
 public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}
*/

public class Solution {
    public ListNode deleteDuplication(ListNode pHead)
    {
        // 如果链表首结点为空 或 链表只有一个结点直接返回这个表头
        if(pHead == null || pHead.next == null){
            return pHead;
        }
        
        // 创建哨兵 head 使得 prev 始终在 cur 前结点
        ListNode head = new ListNode(-1);
        head.next = pHead;
        ListNode prev = head;
        ListNode cur = pHead;
        
        while(cur != null){
            // 判空不能少 ！！！ 只要用到 cur.next.val 就要对 cur.next 判空
             if(cur.next != null && cur.val == cur.next.val){
                 // 找到当前重复数字的最后一个结点
                 while(cur.next != null && cur.val == cur.next.val){
                     cur = cur.next;
                 }
                 // 让 prev 指向 最后一个重复的下一个（不重复的）
                  prev.next = cur.next;
                 
                 // 这种情况说明了链表是以重复的结点结尾的,可以直接返回
                 if(cur.next == null){
                     return head.next;
                 }
                 cur = cur.next;
             }else{
                 // 开始我没写 else 导致程序比较凌乱
                 // prev 前移的条件是 当前结点与下一个结点不相同
                 prev = cur;
                 cur = cur.next;
             }    
            
        }
        return head.next;
    }
}