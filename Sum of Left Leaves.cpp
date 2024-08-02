#include <bits/stdc++.h>
#define ll long long 
class Solution {
 private:
    int sumOfLeftLeavesHelper(TreeNode* node, bool isLeft) {
        if(node == NULL) return 0; // Base case: if the node is null, return 0
        if(node->left == NULL && node->right == NULL && isLeft == true){
            return node->val; // If it's a left leaf, return its value
        }
        // Recursively sum left leaves in both subtrees
        return sumOfLeftLeavesHelper(node->left, true) + sumOfLeftLeavesHelper(node->right, false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
           return sumOfLeftLeavesHelper(root, false);
    }
};

//        3
//       / \
//      9  20
//        /  \
//       15   7
// Dry Run Steps:
// 1. Node = 3, isLeft = false
// Node is not null, not a leaf, so we proceed.
// Recursive call to left child (9) with isLeft = true.
// Recursive call to right child (20) with isLeft = false.
// Node = 9, isLeft = true
// Node is a leaf and isLeft is true.
// Return node value: 9.
// Node = 20, isLeft = false
// Node is not null, not a leaf, so we proceed.
// Recursive call to left child (15) with isLeft = true.
// Recursive call to right child (7) with isLeft = false.
// Node = 15, isLeft = true
// Node is a leaf and isLeft is true.
// Return node value: 15.
// 5. Node = 7, isLeft = false
// Node is a leaf but isLeft is false.
// Return 0.
// Summation:
// Sum from left child of 3 (9) + Sum from right child of 3 (15 from left child of 20 + 0 from right child of 20) = 9 + 15 + 0 = 24. 
