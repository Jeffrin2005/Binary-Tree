/**
time complexity = o(n)
space complexity = o(h)
 */
class Solution {
public:
    int findTilt(TreeNode* root) {
        int totalTilt = 0;
        sumAndTilt(root, totalTilt);
        return totalTilt;
    }

private:
    int sumAndTilt(TreeNode* node, int& totalTilt) {
        if (node == nullptr) return 0;
        if (node->left == nullptr && node->right == nullptr) {
            return node->val;
        }
        int leftSum = sumAndTilt(node->left, totalTilt);
        int rightSum = sumAndTilt(node->right, totalTilt);
        // Calculate the tilt for the current node and add it to the total tilt
        totalTilt += abs(leftSum - rightSum);
        return node->val + leftSum + rightSum;
    }
};
