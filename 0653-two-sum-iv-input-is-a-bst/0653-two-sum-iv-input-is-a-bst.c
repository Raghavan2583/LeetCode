/*
 * Given the root of a Binary Search Tree and a target number k, 
 * return true if there exist two elements in the BST such that 
 * their sum is equal to the given target.
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^4 <= Node.val <= 10^4
 * root is guaranteed to be a valid binary search tree.
 * -10^5 <= k <= 10^5
 *
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
/*
 * Algorithm:
 *          5
 *      3       7
 *     2 4     6 8
 *
 *  2 3 4 5 6 7 8
 *
 *  Traverse each node in BST, search (sum - node value)
 */ 
 
bool binSearch(struct TreeNode* root, int target)
{
    if (root == NULL) {
        return false;
    }
    
    if (root->val == target) {
        return true;
    }
    else if (root->val > target) {
        return binSearch(root->left, target);
    }
    else {
        return binSearch(root->right, target);
    }
}
 
bool dfs(struct TreeNode *root, struct TreeNode *curr, int target)
{
    if (curr == NULL) {
        return false;
    }
    
    if (target - curr->val != curr->val) {
        if (binSearch(root, target - curr->val) == true) {
            return true;
        }
    }
    
    return (dfs(root, curr->left, target) | dfs(root, curr->right, target));
}

bool findTarget(struct TreeNode* root, int k){
    /*
     * Input:
     *  root, root of BST
     *  k, target number k
     */
     
    /*
     * Output:
     *  return true if there exist two elements in the BST such that 
     *  their sum is equal to the given target.
     */
     
    return dfs(root, root, k);
}