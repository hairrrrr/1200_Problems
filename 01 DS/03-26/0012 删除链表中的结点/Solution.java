// **记住，这种方法可行的条件是要删除的不是最后一个结点**

class Solution {
    public void deleteNode(ListNode node) {

        // 用下一个结点的 data 覆盖要被删除结点的 data
        node.val = node.next.val;
        // 将下下个结点的地址放入当前结点的指针域
        node.next = node.next.next;

    }
}