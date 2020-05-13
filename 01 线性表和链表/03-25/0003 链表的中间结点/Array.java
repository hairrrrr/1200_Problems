// 数组法
// 链表的缺点在于不能通过下标访问对应的元素。因此我们可以考虑对链表进行遍历，同时将遍历到的元素依次放入数组 A 中。如果我们遍历到了 N 个元素，那么链表以及数组的长度也为 N，对应的中间节点即为 A[N/2]。
// 这个方法时间复杂度和空间复杂度都是 O(n) 
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode[] arrayNode = new ListNode[100];
        int count = 0;
        ListNode cur = head;

        while(cur != null){
            arrayNode[count++] = cur;
            cur = cur.next;
        }
        return arrayNode[count / 2];
    }
}