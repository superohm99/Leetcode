/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void preorder(struct TreeNode* root, int* returnSize, int* tree) {

    if (root != NULL) {
        tree[*returnSize] = root->val;
        *returnSize += 1;
        preorder(root->left, returnSize, tree);
        preorder(root->right, returnSize, tree);
    }   
}


int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *tree = (int *)malloc(sizeof(int)*100);
    *returnSize = 0;

    preorder(root, returnSize, tree);

    return tree;
}