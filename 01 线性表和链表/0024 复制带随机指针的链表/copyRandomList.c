/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct TreeNode *next;
 *     struct TreeNode *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
	
    if(head == NULL)
        return NULL;

    struct Node* orig_node, *clone_node, *newHead;

    // 1. 复制结点
    orig_node = head;
    while(orig_node != NULL){
        clone_node = (struct Node*)malloc(sizeof(struct Node));
        clone_node->val = orig_node->val;
        clone_node->next = orig_node->next;
        orig_node->next = clone_node;
        orig_node = clone_node->next;
    }

    // 2. 复制随机指针
    orig_node = head;
    while(orig_node != NULL){
        orig_node->next->random = (orig_node->random == NULL) ? NULL : orig_node->random->next;
        orig_node = orig_node->next->next;
    }

    // 3. 拆链
    orig_node = head;
    clone_node = orig_node->next;
    newHead = clone_node;
    while(orig_node != NULL){
        orig_node->next = orig_node->next->next;
        clone_node->next = (clone_node->next == NULL)? NULL : clone_node->next->next;
        orig_node = orig_node->next;
        clone_node = clone_node->next;
    }

    return newHead;
}
