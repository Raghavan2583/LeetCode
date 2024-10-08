/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getHeight(struct TreeNode * root, int node, int height)
{
    if(root == NULL) return 0;
    if(node == root->val)
        return height;
    int h = getHeight(root->left, node, height + 1);
    if(h != 0)
        return h;
    return getHeight(root->right, node, height + 1);    
}

bool sameParents(struct TreeNode * root, int x, int y)
{
    if(root == NULL) return false;
    if((root->left != NULL && root->right != NULL)&& ((root->left->val == x && root->right->val == y) || (root->left->val == y && root->right->val == x)))
        return true;
    return sameParents(root->left, x, y) || sameParents(root->right, x, y);
}

bool isCousins(struct TreeNode* root, int x, int y){
    if(getHeight(root, x, 1) != getHeight(root, y, 1))
        return false;
    if(sameParents(root, x, y))
        return false;
    return true;
}