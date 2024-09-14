class Solution {
public:
     void traverse(Node* node, std::vector<int>& result) {
        if(node == NULL) return;
        result.push_back(node->val);  // Visit the root of the subtree
        for(auto&child : node->children) {  // Recursively visit all the children
            traverse(child, result);
        }
    }
    vector<int> preorder(Node* root) {
       vector<int>result;
        traverse(root, result);
        return result;
    }
};
