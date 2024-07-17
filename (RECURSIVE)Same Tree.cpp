/**
time complexity = o(n)
space complexity = o(h)
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q){
        // If both nodes are null, trees are same at this branch
        if (p ==NULL && q==NULL) return true;
        if (p==NULL or q==NULL or p->val != q->val) return false;
        bool left_same = isSameTree(p->left, q->left);
        bool right_same = isSameTree(p->right, q->right);
        return left_same && right_same; 
    }
};
