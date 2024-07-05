/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int len_left = 0;
    int len_right = 0;
    if (root == NULL)
        return 0;
    len_left = maxDepth(root->left);
    len_right = maxDepth(root->right);
    if (len_left > len_right)
        return len_left + 1;
    else
        return len_right + 1;
}