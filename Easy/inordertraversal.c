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

void inorder(struct TreeNode* root, int* returnSize, int* tree) {

    if (root != NULL) {
        inorder(root->left, returnSize, tree);
        tree[*returnSize] = root->val;
        *returnSize += 1;
        inorder(root->right, returnSize, tree);
    }

}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *tree = (int *)malloc(sizeof(int)*100);
    *returnSize = 0;

    inorder(root, returnSize, tree);

    return tree;
}