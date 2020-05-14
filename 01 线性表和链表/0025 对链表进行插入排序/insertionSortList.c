/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head){

    if(head == NULL || head->next == NULL)
        return head;

    struct ListNode dummyHead;
    struct ListNode* prev = head, *cur = head->next;

    dummyHead.next = head;

    while(cur != NULL){
        if(cur->val < prev->val){
            struct ListNode* find = &dummyHead;

            while(find->next->val < cur->val){
                find = find->next;
            }
            
            prev->next = cur->next;

            cur->next = find->next;
            find->next = cur;

            cur = prev->next;
        }
        else{
            prev = prev->next;
            cur = cur->next;
        }
    }

    return dummyHead.next;
}
