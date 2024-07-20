/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode NODE;

void compute(NODE * curr, int * comp, int * hlist, NODE* p, int height, NODE* sibnode, int level)
{
    if (curr == NULL)
        return;
    
    if (p == NULL)
        comp[curr->val] = -1;
    else if ((comp[p->val] == height) ||
                ((sibnode != NULL) &&
                (hlist[sibnode->val] >= hlist[curr->val])))
        comp[curr->val] = height;               
    else
    {
        /* (sibling height + parent node level + 1) > computed value of parent 
         * then "v1"" else "comp[parent]""
         * Parent level = level -1
         * Hence sh + (level -1) + 1 ==> sh + level */
        int v1 = ((sibnode == NULL) ? -1 : (hlist[sibnode->val])) + level;
        comp[curr->val] = comp[p->val] > v1 ? comp[p->val] : v1;
    }

    compute(curr->left,  comp, hlist, curr, height, curr->right, level + 1);
    compute(curr->right, comp, hlist, curr, height, curr->left, level + 1);
}

int traverse(NODE * curr, int * hlist)
{
    if (curr == NULL)
        return -1;

    int h1 = traverse(curr->left, hlist);
    int h2 = traverse(curr->right, hlist);

    hlist[curr->val] = ((h1 > h2) ? (h1) : (h2)) + 1;

    return hlist[curr->val];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* treeQueries(struct TreeNode* root, int* queries, int queriesSize, int* returnSize)
{
    * returnSize = 0;

    int * answer = malloc(sizeof(int) * queriesSize);
    int * hlist  = malloc(sizeof(int) * 100001);
    int * comp = malloc(sizeof(int) * 100001);

    int h = traverse(root, hlist);

    compute(root, comp, hlist, NULL, h, NULL, 0);

    for (int i = 0; i < queriesSize; i++)
    {
        (*returnSize) ++;
        answer[i] = comp[queries[i]];
    }

    free(hlist);
    free(comp);

    return answer;
}