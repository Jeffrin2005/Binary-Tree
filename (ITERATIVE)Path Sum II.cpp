class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
          vector<vector<int>> result;
        if (root == NULL) return result;
        // Stack to store the node along with the path and current sum
        stack<pair<TreeNode*, pair<vector<int>, int>>> s;
           // Stack to store pairs of (node, (path, currentSum))
        s.push({root, {{root->val}, root->val}});

        while (!s.empty()) {
            auto current = s.top();
            s.pop();
            TreeNode* node = current.first;
            vector<int> path = current.second.first;
            int currentSum = current.second.second;
            // Check if it's a leaf node and the path sum equals targetSum
            if(node->left == NULL && node->right == NULL && currentSum == targetSum){
                result.push_back(path);
            }
            // Push left child to stack if it exists
            if (node->left != NULL){
                vector<int> newPath = path;
                newPath.push_back(node->left->val);
                s.push({node->left, {newPath, currentSum + node->left->val}});
            }
            // Push right child to stack if it exists
            if(node->right != NULL){
                vector<int> newPath = path;
                newPath.push_back(node->right->val);
                s.push({node->right, {newPath, currentSum + node->right->val}});
            }
        }

        return result;
    
    }
};
