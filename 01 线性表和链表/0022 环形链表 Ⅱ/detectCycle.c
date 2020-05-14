/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    
    struct ListNode* fast = head, *slow = head;

    while(1){
        if(fast == NULL || fast->next == NULL)
            return NULL;

        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
            break;
    }

    fast = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}
