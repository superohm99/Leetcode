/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* cur;
    struct ListNode* temp;

    cur = head;
    while (cur != NULL && cur->next != NULL) {
        
        if (cur->val == cur->next->val) {
            temp = cur->next->next;
            free(cur->next);
            cur->next = temp;
        } else {
            cur = cur->next;
        }
    }
    return head;
}