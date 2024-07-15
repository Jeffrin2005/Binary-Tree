class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        //if the node is null, return true( we just reach and all conditions satisfies);
        if (root == NULL) return true;
        // Check the left subtree, if it's not unival or its value differs from root, return false
       if (root->left != NULL && (root->left->val != root->val || isUnivalTree(root->left) == false)) return false;
        // Check the right subtree, if it's not unival or its value differs from root, return false
     if (root->right != NULL && (root->right->val != root->val || isUnivalTree(root->right) == false)) return false;
        return true;
    }
};
