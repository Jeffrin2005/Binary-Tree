class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
    if (root==NULL) return result;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int levelSize = q.size(); // Number of elements at the current level
        vector<int> currentLevel;
        for (int i = 0; i < levelSize;i++){
            TreeNode* node = q.front();
            q.pop();
            currentLevel.push_back(node->val);
            // Enqueue left child
            if(node->left != NULL) {
                q.push(node->left);
            }
            // Enqueue right child
            if (node->right != NULL ) {
                q.push(node->right);
            }
        }
        result.push_back(currentLevel);
    }

    return result;
    }
};
