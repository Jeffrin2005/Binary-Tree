/**
 time complexity = o(n1 + n2)
 space complexity = O(L1 + L2)
 */
class Solution {
private:
    void dfs(TreeNode* root, string &s) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL){
            s+=to_string(root->val) + "*";
        }
        dfs(root->left, s);
        dfs(root->right, s);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string t1, t2;
        dfs(root1, t1);
        dfs(root2, t2);
        if(t1==t2) return true;
        else return false; 
    }
};
