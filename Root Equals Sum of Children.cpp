
class Solution {
public:
    // time complexity = o(1);  
    // space complexity = o(1);
    bool checkTree(TreeNode* root) {
        if(root == NULL) return true;
        int leftans =0;
        int rightans = 0;
        if(root->left != NULL){
            leftans = root->left->val;
        }
        if(root->right != NULL){
            rightans = root->right->val;
        }
        int temp = leftans + rightans;
        if(root->val == temp) return true;
        else return false; 

        
    }
};
