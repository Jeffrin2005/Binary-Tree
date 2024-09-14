#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        stack<pair<TreeNode*,int>> stack;
        stack.push({root, 1});
        int minDepth = INT_MAX;
        while(!stack.empty()){
            auto current = stack.top();
            stack.pop();
            TreeNode* node = current.first;
            int depth = current.second;
            // Check if it's a leaf node
            if (node->left == NULL && node->right == NULL) {
                minDepth = min(minDepth, depth);
            }  // Correctly push non-null children onto the stack
              if(node->left != NULL){
                stack.push({node->left, depth + 1});
            }
          
            if(node->right != NULL){
                stack.push({node->right, depth + 1});
            }
          
        }

        return minDepth;
    }
};
