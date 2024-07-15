
class Solution {
public:
// time compleixty = o(n)
// space complexity = o(n)
    bool isUnivalTree(TreeNode* root) {
        if (root == NULL) return true;
        int uniValue = root->val; 
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* currentNode = q.front();
            q.pop();
            if (currentNode->val != uniValue) return false;
            // If the left child exists, add it to the queue
            if (currentNode->left != NULL) q.push(currentNode->left);
            // If the right child exists, add it to the queue
            if (currentNode->right != NULL) q.push(currentNode->right);
        }
        return true;
    }
};
