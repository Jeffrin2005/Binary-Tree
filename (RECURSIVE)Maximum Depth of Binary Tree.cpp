
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // time complexity = o(n)
        // space complexity = o(log(n))
        if(root==NULL){
            return 0 ;
        }
        int left= 1 + maxDepth(root->left);
        int right = 1 + maxDepth(root->right);
        int ans = max(left, right);
        return ans; 
        
    }
};
