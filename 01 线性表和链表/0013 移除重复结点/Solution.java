/*如果是排序的，那方法和 0011 题一样，但是当前链表是未排序的。

所以，这道题我的思路是：用 node 遍历整个链表。把每个 node 的值都与当前整个链表后面的元素比较。删除操作其实和 0011 差不多。

复杂度是：O(n^2) 我在网上也没看到比较适合新手的解法1，用哈希好像也是O(n^2)，所以我觉得能自己写出来不错了，以后再优化。下面是我的做法：
*/

class Solution {
    // 这个函数只能排有序的
    public ListNode removeDuplicateNodes(ListNode head) {
        
        if(head == null || head.next == null){
            return head;
        }

        ListNode node = head;
        ListNode prev = head;
        ListNode cur;

        // 不要随便用 node.next 判断
        while(node != null){
                // 从当前 noed 开始,遍历一遍链表，寻找是否有重复
                cur = prev.next;
                while(cur != null){
                    if(cur.val == node.val){
                        cur = cur.next;
                        prev.next = cur;
                    }else{
                        prev = cur;
                        cur = cur.next;
                    }
                }
            	// node 前移
                node = node.next;
                prev = node;
                
            }
        
        return head;
    }
}