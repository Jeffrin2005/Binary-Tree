/**
time comp =o(n) space comp = o(h)
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int height(TreeNode* node, int& diameter) {
        if (node == NULL) return 0;
        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);
        int localDiameter = leftHeight + rightHeight;
        diameter = max(diameter, localDiameter);
        return 1 + max(leftHeight, rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root){
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};
