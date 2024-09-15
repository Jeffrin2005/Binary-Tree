#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
class Solution {
private:
    map<int, int>inorderIndexMap;
    int preorderIndex = 0;
    TreeNode* buildTreeRecursive(vector<int>& preorder, vector<int>& inorder, int left, int right){
        if(left > right) return NULL;
        // The current root value is at preorderIndex in preorder array
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);
        // Build the left and right subtrees recursively
        root->left = buildTreeRecursive(preorder, inorder, left, inorderIndexMap[rootValue] - 1);
        root->right = buildTreeRecursive(preorder, inorder, inorderIndexMap[rootValue] + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        // Create a map to store the index of each value in inorder array for quick access
        for(int i = 0; i < inorder.size(); i++){
            inorderIndexMap[inorder[i]] = i;
        }

        return buildTreeRecursive(preorder, inorder, 0, inorder.size() - 1);
    }
};
