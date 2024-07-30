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
// time comp = o(n) space comp = o(h)
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
           stack<TreeNode*> stack;
        TreeNode* prev = NULL;
        int minDiff = INT_MAX;
        // Start from the root node
        TreeNode* current = root;
        while(!stack.empty() || current != NULL){
            // Reach the leftmost node of the current node
            while(current != NULL){
                stack.push(current);
                current = current->left;
            }
            // current must be NULL at this point , leaf node
            current = stack.top();
            stack.pop();
            // Process the current node
            if(prev != NULL){
                minDiff = min(minDiff, current->val - prev->val);
            }
            prev = current;
            // Move to the right subtree
            current = current->right;
        }

        return minDiff;
    }
};
