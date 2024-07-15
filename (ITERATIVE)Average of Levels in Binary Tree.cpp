class Solution {
public:
// time complxity = o(n)
// space compleixty = o(n)
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> ans;
        q.push(root);
        while(!q.empty()){ 
            int n = q.size();
            double sum = 0;
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            ans.push_back(sum / n);
        }
        return ans; 
    }
};
