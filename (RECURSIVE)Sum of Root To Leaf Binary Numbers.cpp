
class Solution {
private:
// time complexity = o(n)
// space compleixty = o(log(n))
    int helper(TreeNode* node, int currentSum) {
        if (node == NULL) return 0;
        // Multiply current sum by 2 and add current node's value
        currentSum = currentSum * 2 + node->val;
        // If it's a leaf node, return the current sum
        if (node->left == NULL && node->right == NULL){
            return currentSum;
        }
        return helper(node->left, currentSum) + helper(node->right, currentSum);
    }
    public:
    int sumRootToLeaf(TreeNode* root) {
        return helper(root, 0);
    }
};
