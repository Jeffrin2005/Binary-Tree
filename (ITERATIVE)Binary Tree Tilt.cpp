

/**
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
public:
    int findTilt(TreeNode* root) {
        if (root==NULL) return 0;
        int totalTilt = 0;
       stack<TreeNode*> stack;
       map<TreeNode*, int> sums;
        // Post-order traversal using a stack
        TreeNode* last = NULL;
        TreeNode* node = root;
        while (!stack.empty() || node != NULL) {
            if (node != NULL) {
                stack.push(node);
                node = node->left;
            } else {
                TreeNode* peekNode = stack.top();
                if (peekNode->right != NULL && last != peekNode->right) {
                    node = peekNode->right;
                } else {
                    stack.pop();
                    int leftSum = sums[peekNode->left];
                    int rightSum = sums[peekNode->right];
                    int sum = peekNode->val + leftSum + rightSum;
                    sums[peekNode] = sum;
                    totalTilt+=abs(leftSum - rightSum);
                    last = peekNode;
                }
            }
        }
        return totalTilt;
    }
};
