class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> queue_p, queue_q;
        queue_p.push(p);
        queue_q.push(q);
        while (!queue_p.empty() && !queue_q.empty()) {
            TreeNode* node_p = queue_p.front();
            TreeNode* node_q = queue_q.front();
            queue_p.pop();
            queue_q.pop();
            if(node_p==NULL && node_q==NULL) continue; // Both nodes are null, continue
            if(node_p==NULL || node_q==NULL) return false; // One of them is null, trees are not the same
            if(node_p->val != node_q->val) return false; // Values do not match
            queue_p.push(node_p->left);
            queue_p.push(node_p->right);
            queue_q.push(node_q->left);
            queue_q.push(node_q->right);
        }
        return queue_p.empty() && queue_q.empty(); // Both should be empty if trees are the same
    }
};
