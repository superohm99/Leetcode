/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p == NULL && q == NULL)
        return true;
    if(p == NULL || q == NULL)
        return false;

    if(p->val != q->val)
        return false;
    
    bool check_left = isSameTree(p->left, q->left);
    bool check_right = isSameTree(p->right, q->right);


    return check_left && check_right;
}