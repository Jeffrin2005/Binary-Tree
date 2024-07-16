/**
time complexity = o(n1 + n2)
space complexity = o(n1 + n2);
 */
class Solution {
private:
    void collectLeaves(TreeNode* root, string &s) {
        if (root == NULL) return;
        stack<TreeNode*> stack;
        stack.push(root);
        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();
            // Check if it's a leaf node
            if (node->left == NULL && node->right == NULL){
                s += to_string(node->val) + "*";
            }
            if(node->right != NULL) stack.push(node->right);
            if(node->left != NULL) stack.push(node->left);
        }
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string t1, t2;
        collectLeaves(root1, t1);
        collectLeaves(root2, t2);
        return t1 == t2;
    }
};
