class Solution {
public:
    int minDepth(TreeNode* root) {
        // Base case: if the tree is empty
        if (root == NULL) return 0;
        // If left child is NULL, recursively find the min depth of the right subtree
        if (root->left == NULL ) return 1 + minDepth(root->right);
        // If right child is NULL, recursively find the min depth of the left subtree
        if (root->right == NULL ) return 1 + minDepth(root->left);

        // If both children exist, find the minimum of the depths of the two subtrees
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
