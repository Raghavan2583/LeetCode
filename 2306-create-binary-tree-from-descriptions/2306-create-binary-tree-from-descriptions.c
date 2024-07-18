/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode list;

list* do_node (int a){
    list* ret = (list*)malloc(sizeof(list));
    if(ret == NULL) exit(1);
    ret->val = a;
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}

struct TreeNode* createBinaryTree(int** des, int desSize, int* desColSize) {
    list* arr[100001] = {0}; //hash table
    int val_root = 0;

    for(int t = 0; t < desSize; ++t){
        int parent = des[t][0];
        int child = des[t][1];
        if(!arr[parent]){
            arr[parent] = do_node(parent);
            val_root += parent;
        }
        if(!arr[child]){
            arr[child] = do_node(child);
            val_root += child;
        }
        if(des[t][2]) arr[parent]->left = arr[child];
        else arr[parent]->right = arr[child];
        val_root -= child;
    }
    return arr[val_root];
}