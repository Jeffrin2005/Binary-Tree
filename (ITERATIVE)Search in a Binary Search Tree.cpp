// time complexity = o(log(n));
// space complexity = o(1)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
            while(root != NULL and root->val != val){
                if(val < root->val){
                    root = root->left;
                }else{
                    root = root->right;
                }
            }
            return root;
    }
};
