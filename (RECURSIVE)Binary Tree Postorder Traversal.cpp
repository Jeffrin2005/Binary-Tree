/**
time compleixty = o(n)
space compleixty  = o(log(n))
 */
/*
 */
class Solution {
    private:
    void postorder(TreeNode* node, vector<int>& result){
        if(node==NULL) return;
        postorder(node->left, result); 
        postorder(node->right, result); 
        result.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> result;
        postorder(root, result);
        return result;
    }
};
