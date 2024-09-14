class Solution {
private:
    bool isValidBSTHelper(TreeNode* node, long minVal, long maxVal) {
        if (node == NULL ) return true; // An empty tree is a valid BST
        // Check if the current node's value is within the valid range
        if(node->val <= minVal || node->val >= maxVal) return false;
        // Recursively validate the left and right subtree
        return isValidBSTHelper(node->left, minVal, node->val) &&   isValidBSTHelper(node->right, node->val, maxVal);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }
};// DRY RUN 
//     10
//    /  \
//   5    15
//       /  \
//      6    20

// minVal = LONG_MIN, maxVal = LONG_MAX
// Check if 10 is between LONG_MIN and LONG_MAX. It is, so we proceed.

// Recursive call to left child with range LONG_MIN to 10.
// Recursive call to right child with range 10 to LONG_MAX.

// 2. Left Child of Root (5):
// minVal = LONG_MIN, maxVal = 10
// Check if 5 is between LONG_MIN and 10. It is, so we proceed.
// Recursive calls to its children (both null) will return true.

// 3. Right Child of Root (15):
// minVal = 10, maxVal = LONG_MAX
// Check if 15 is between 10 and LONG_MAX. It is, so we proceed.
// Recursive call to its left child with range 10 to 15.
// Recursive call to its right child with range 15 to LONG_MAX.

// Left Child of Node 15 (6):
// minVal = 10, maxVal = 15
// Check if 6 is between 10 and 15. It is not, as 6 is less than 10.
// The condition if (node->val <= minVal || node->val >= maxVal) evaluates to true because 6 <= 10.
// The function returns false immediately, indicating a violation of the BST properties.
