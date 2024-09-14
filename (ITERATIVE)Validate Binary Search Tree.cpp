#include <bits/stdc++.h>
#define ll long long 
#define nl '\n'
class Solution {
public:
    bool isValidBST(TreeNode* root) {
           // If the tree is empty, it is considered a valid BST
        if(root == NULL ) return true;
        // Stack to hold nodes along with the min and max values 
       stack<pair<TreeNode*,pair<ll,ll>>> stack;
        // Initialize the stack with the root node and the entire range of long values
stack.push({root, {LONG_MIN, LONG_MAX}});
        while(!stack.empty()){
            // Retrieve the top element from the stack
            auto node_info = stack.top();
            stack.pop();
            //extract the node and its value range
            TreeNode* node = node_info.first;
            ll minVal = node_info.second.first;
            ll maxVal = node_info.second.second;
            // Check if the current node's value is within the valid range
            if(node->val <= minVal || node->val >= maxVal) return false;
             if(node->left != NULL) {// If the node has a left child, push it onto the stack with updated max value
                stack.push({node->left, {minVal, node->val}});
            }
             if(node->right != NULL){  // If the node has a right child, push it onto the stack with updated min value
                stack.push({node->right, {node->val, maxVal}});
            } 
            
           
        }
        return true;
    }
};
