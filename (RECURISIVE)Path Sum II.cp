#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
class Solution {
public:
    void check(TreeNode* node, int currentSum, vector<int>& path, vector<vector<int>>& result, int targetSum) {
        if(node == NULL) return;
        // Add the current node's value to the path and update the current sum.
        path.push_back(node->val);
        currentSum += node->val;

        // Check if the current node is a leaf and if the current sum equals the target sum.
        if(node->left == NULL && node->right == NULL && currentSum == targetSum){
            result.push_back(path);
        }
        // Recursively visit the left and right children.
        check(node->left, currentSum, path, result, targetSum);
        check(node->right, currentSum, path, result, targetSum);
        // Backtrack: remove the current node from the path before returning.
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        check(root, 0, path, result, targetSum);
        return result;
    }
};
