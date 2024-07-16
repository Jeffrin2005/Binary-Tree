// time complexity = o(n)
// space complexity = o(log(n))

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;
        preorder(root, result);
        return result;
    }
private:
    void preorder(TreeNode* node, vector<int>& result) {
        if(node == NULL){
            return;
        }
        result.push_back(node->val);
        // Traverse the left subtree
        preorder(node->left, result);
        // Traverse the right subtree
        preorder(node->right, result);
    }
};
