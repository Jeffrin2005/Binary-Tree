class Solution {
public:
   vector<vector<int>> result;
    void traverse(TreeNode* node, int level, bool leftToRight) {
        if(node==NULL) return;
        // Ensure the current level is present in the result vector
        if(level >= result.size()) result.push_back({});
        // Add the current node's value to the corresponding level
        if(leftToRight){
            result[level].push_back(node->val);
        }else{
            result[level].insert(result[level].begin(), node->val);
        }

        // Recursively traverse the next level
        traverse(node->left, level + 1, !leftToRight);
        traverse(node->right, level + 1, !leftToRight);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        traverse(root, 0, true);  // Start from level 0, left to right
        return result;
    }
};
