
class Solution {
public:
  // time complexity = o(n) where n is the node of nodes
// space complexity = o(h) where is h is the height of the tree 
    bool evaluateTree(TreeNode* root) {
        if(root->left == NULL && root->right == NULL){
            if(root->val == 1) return true;
            else return false; 
        }
        bool leftcheck = evaluateTree(root->left);
        bool rightcheck = evaluateTree(root->right);
        if(root->val == 2){
            return leftcheck || rightcheck;
        }else if(root->val == 3){
            return leftcheck && rightcheck;
        }
        return false; 
        
    }
};
