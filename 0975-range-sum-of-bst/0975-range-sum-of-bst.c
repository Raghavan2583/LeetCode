/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rangeSumBST(struct TreeNode* root, int low, int high) {
    struct TreeNode *stack[10000], *node;
    int sum = 0, sp = 0, val;
    if (root != NULL) {
        stack[sp++] = root;
    }
    while (sp > 0) {
        node = stack[--sp];
        val = node->val;
        if (val >= low && val <= high) {
            sum += node->val;
        }
        if (val <= high && node->right != NULL) {
            stack[sp++] = node->right;
        }
        if (val >= low && node->left != NULL) {
            stack[sp++] = node->left;
        }
    }
    return sum;
}