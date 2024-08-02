
class Solution {
public:
    map<int, int>count;
    int maxCount = 0;
    void inorder(TreeNode* node){
        if(node ==  NULL) return;
        inorder(node->left);
        // Increment the count for the current node's value
        count[node->val]++;
        // Update maxCount if the current count of node->val is greater
        if(count[node->val] > maxCount){
            maxCount = count[node->val];
        }
        inorder(node->right);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        //  in-order traversal to count frequencies
        inorder(root);
        // Collect all values with the maximum frequency
        for(auto&x : count){
            if(x.second == maxCount){
                modes.push_back(x.first);
            }
        }

        return modes;
    }
};
