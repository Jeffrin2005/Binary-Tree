class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        // Stack to store pairs of TreeNode* and the current path sum
        stack<pair<TreeNode*,int>> s;
        s.push(make_pair(root, root->val));
        while(!s.empty()){
            pair<TreeNode*, int> top = s.top();
            s.pop();
            TreeNode* node = top.first;
            int currSum = top.second;
            // Check if it's a leaf node and if the path sum equals the targetSum
            if(node->left == NULL && node->right == NULL && currSum == targetSum){
                return true;
            }
            // Push children to stack with updated path sums
            if(node->right != NULL){
                s.push(make_pair(node->right, currSum + node->right->val));
            }
            if(node->left != NULL){
                s.push(make_pair(node->left, currSum + node->left->val));
            }
        }
        return false;
    }
};
