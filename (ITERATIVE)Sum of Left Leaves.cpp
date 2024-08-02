class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        int sum = 0;
        stack<pair<TreeNode*, bool>> stk; // Stack to hold nodes and a flag indicating if it's a left child
        stk.push({root, false}); // Start with the root node, which is not a left child
        while(!stk.empty()){
            auto [node, isLeft] = stk.top(); // Get the current node and whether it's a left child
            stk.pop();
            if(node == NULL) continue; // If the node is null, continue to the next iteration
            // Check if the current node is a leaf and a left child
            if(isLeft == true && node->left ==NULL && node->right == NULL) {
                sum+=node->val; // Add the node's value to sum if it's a left leaf
            }
            // Push children to the stack
            stk.push({node->right, false}); // Right child is not a left child
            stk.push({node->left, true}); // Left child is a left child
        }

        return sum;
    }
};
