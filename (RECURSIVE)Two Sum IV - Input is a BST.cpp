class Solution {
public:
    bool dfs(TreeNode* node, set<int>& seen, int k) {
        if(node==NULL) return false;
        if(seen.count(k - node->val)) return true;
        seen.insert(node->val);
        return dfs(node->left, seen, k) || dfs(node->right, seen, k);
    }

    bool findTarget(TreeNode* root, int k) {
        set<int> seen;
        return dfs(root, seen, k);
    }
};
