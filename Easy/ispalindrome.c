/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode* set[100000];
    struct ListNode* temp;
    int i;
    // int j;

    i = 0;
    temp = head;
    while (temp) {
        set[i] = temp;
        temp = temp->next;
        i++;
    }

    temp = head;
    printf("%d ",i);
    while (i > 0) {
        if (set[--i]->val != temp->val)
            return false;
        temp = temp->next;
    }

    return true;
}