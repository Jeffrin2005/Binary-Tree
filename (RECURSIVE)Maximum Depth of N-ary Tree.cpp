

class Solution {
public:
    int maxDepth(Node* root) {
      if(root == NULL)   return 0;
        int max_child_depth = 0;
        for(auto&child : root->children){
            max_child_depth =max(max_child_depth, maxDepth(child));
        }
        return 1 + max_child_depth;   
    }
};
