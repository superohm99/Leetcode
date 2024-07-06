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

void postorder(struct TreeNode* root, int* returnSize, int* tree) {

    if (root != NULL) {

        postorder(root->left, returnSize, tree);
        postorder(root->right, returnSize, tree);
        tree[*returnSize] = root->val;
        *returnSize += 1;
    }

}


int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int *tree = (int *)malloc(sizeof(int)*100);
    *returnSize = 0;

    postorder(root, returnSize, tree);
    return tree;
}