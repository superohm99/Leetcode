/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    struct ListNode* swap = NULL;
    struct ListNode* temp;
    struct ListNode* set[50000];
    int i;
    int j;
    int k;
    
    i = 0;
    j = 0;
    temp = head;
    while (temp != NULL) {
        set[i] = temp;
        temp = temp->next;
        i++;
    }
    k = i;
    temp = head;
    
    while (j < (k / 2)) {
        swap = temp->next;
        temp->next = set[--i];
        temp->next->next = swap;
        temp = swap;
        j++;
    }
    temp->next = NULL;
}