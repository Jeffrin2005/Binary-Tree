
class Solution {
private:
    int helper(TreeNode* node, string path){
        if(node == NULL) return 0;
        // Append current node's value to the path string
        path+=to_string(node->val);
        // If it's a leaf node, convert the binary string to decimal
        if(node->left == NULL and  node->right == NULL){
            return stoi(path, NULL, 2); // Convert binary string to decimal (2 = a base-2 (binary) number)
        }
        return helper(node->left, path) + helper(node->right, path);
    }
public:
    int sumRootToLeaf(TreeNode* root){
        return helper(root, "");
    }
};
