// 先摆上一个笨比写法，没错就是我写的：

class Solution {
    public void deleteNode(ListNode node) {
		
        // 创建哨兵结点
        ListNode Node = new ListNode(-1);
        ListNode prev = Node;
        
        prev.next = node;
        ListNode cur = node;
        ListNode Next = cur.next;

		// 从链表要删除的结点开始，将下一个结点的 data 赋值给 当前结点的 data，完成目标结点值覆盖
        while(cur.next != null){
            cur.val = Next.val;
            cur = cur.next;
            Next = cur.next;
            prev = prev.next; 
        }
        // 将倒数第二个结点的指针域置为空
        prev.next = null;

    }
}

/* 反思

其实完全不用这么麻烦，刷了这么多题，思维有点被束缚住。思维要开放一点，链表的删除不用像数组那样用循环去做。虽然不能删除当前要被删除的结点，但是可以删除下一个结点啊！！！
*/