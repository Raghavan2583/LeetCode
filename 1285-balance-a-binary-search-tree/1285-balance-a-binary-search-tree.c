struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorder(struct TreeNode* root, int* a, int* index) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, a, index);
    a[(*index)++] = root->val;
    inorder(root->right, a, index);
}

struct TreeNode* buildBalancedBST(int* a, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    struct TreeNode* root = newNode(a[mid]);
    root->left = buildBalancedBST(a, start, mid - 1);
    root->right = buildBalancedBST(a, mid + 1, end);
    return root;
}

struct TreeNode* balanceBST(struct TreeNode* root) {
    int a[10001];
    int index = 0;
    inorder(root, a, &index);
    return buildBalancedBST(a, 0, index - 1);
}