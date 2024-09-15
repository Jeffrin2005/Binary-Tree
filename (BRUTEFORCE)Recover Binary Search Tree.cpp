class Solution {
private:
    void inorderTraversal(TreeNode* node, vector<TreeNode*>& nodes,vector<int>& values) {
        if (node == NULL) return;
        inorderTraversal(node->left, nodes, values);
        nodes.push_back(node);
        values.push_back(node->val);
        inorderTraversal(node->right, nodes, values);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
     vector<int> values;
        // Step 1: In-order traversal to collect nodes and their values
        inorderTraversal(root, nodes, values);
        // Step 2: Sort the values to find the correct order
        std::sort(values.begin(), values.end());
        // Step 3: Assign the sorted values back to the nodes
        for (int i = 0; i < nodes.size();i++){
            nodes[i]->val = values[i];
        }
    }
};
