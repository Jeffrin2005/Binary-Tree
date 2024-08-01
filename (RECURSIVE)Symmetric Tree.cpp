// TIME COMP = O(N) SPACE COMP = O(N)
        //      1
      //      /   \
    //       2     2
   //       / \   / \
  //       3   4 4   3

//  Root Node: The root is 1, and we start by comparing its left child (2) with its right child (2).
// First Recursive Call: isMirror(left->left, right->right)
// This compares the left subtree of the left child (3 from the left 2) with the right subtree of the right child (3 from the right 2).
// Since both are 3, they are mirrors of each other at this node.
// Second Recursive Call: isMirror(left->right, right->left)
// This compares the right subtree of the left child (4 from the left 2) with the left subtree of the right child (4 from the right 2).
// Since both are 4, they are also mirrors of each other at this node.
class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true; 
        if (left == NULL  || right == NULL ) return false; // Only one subtree is empty
        if (left->val != right->val) return false; 
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL ) return true; // An empty tree is symmetric
        return isMirror(root->left, root->right); // Check if left and right subtrees are mirrors of each other
    }
};
