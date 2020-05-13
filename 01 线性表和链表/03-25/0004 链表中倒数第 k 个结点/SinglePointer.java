public class Solution {
    public ListNode FindKthToTail(ListNode head,int k) {
        ListNode cur = head;
        int len = 0;
        // 计算出链表长度
        while(cur != null){
            cur = cur.next;
            len++;
        }
        
        // 1 表示 cur 从第一位开始遍历
        int i = 1;
        cur = head;
        // 注意 null 的判别，如果输入不合法的 k 可能会越界
        while(cur != null && i != len - k + 1 ){ // 倒数第 k 个就是正数第 len - k + 1 个 
            i++;
            cur = cur.next;
        }
        
        return cur;
    }
}