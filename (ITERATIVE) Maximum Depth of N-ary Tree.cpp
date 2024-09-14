

class Solution {
public:
    int maxDepth(Node* root) {
      if(root == NULL) return 0;
        queue<Node*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            int size = q.size(); // Number of nodes at the current level
            for(int i = 0; i < size;i++){
                Node* node = q.front();
                q.pop();
                // Enqueue all children of the current node
                for(auto&child : node->children) {
                    q.push(child);
                }
            }
            depth++; // Increment depth as we complete each level
        }

        return depth;
    }
};
