class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            // Number of nodes at the current level
            int size = q.size();
            // Process each node at the current level
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front(); 
                q.pop(); 
                // If the node has a left child, add it to the queue
                if(node->left != NULL) q.push(node->left);
                // If the node has a right child, add it to the queue
                if(node->right != NULL) q.push(node->right);
            }
            depth++;
        }

        return depth;
    }
};
