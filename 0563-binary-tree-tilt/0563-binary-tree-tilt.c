/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int traversal(struct TreeNode * root, int * total_tilt)
{
    if(root)
    {
        int l_sum = traversal(root->left, total_tilt);
        int r_sum = traversal(root->right, total_tilt);

        *total_tilt += (l_sum >= r_sum) ? (l_sum - r_sum) : (r_sum - l_sum);
        return (l_sum + r_sum + root->val);
    }
    return 0;
}

int findTilt(struct TreeNode* root) 
{
    int total_tilt = 0;

    traversal(root, &total_tilt);
    return total_tilt;
}