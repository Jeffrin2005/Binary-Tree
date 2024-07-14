

class Solution {
public:
// time complexity = o(n);
// space compleixty = o(log(n))
    void bfs(TreeNode* root, map<TreeNode*, bool>& visited) {
        if (root == NULL) {
            return;
        }
        if(visited[root]){
            return;
        }
      queue<TreeNode*> q;  
        q.push(root);  
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (visited[current]) {
                continue;
            }
            visited[current] = true;
            TreeNode* temp = current->left;
            current->left = current->right;
            current->right = temp;
            // Enqueue non-null children
            if (current->left != NULL) {
                q.push(current->left);
            }
            if (current->right != NULL) {
                q.push(current->right);
            }
        }
    }

    TreeNode* invertTree(TreeNode* root) {
     map<TreeNode*, bool> visited;
        bfs(root, visited); 
        return root;
    }
};
