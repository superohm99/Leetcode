/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void flatten(struct TreeNode* root) {
    
    if (root != NULL) {

        struct TreeNode* temp = root->right;

        root->right = root->left;
        root->left = NULL;

        struct TreeNode* check_root = root;
        while (check_root->right != NULL) {
            check_root = check_root->right;
        }
        check_root->right = temp;

        flatten(root->right);
    }
}