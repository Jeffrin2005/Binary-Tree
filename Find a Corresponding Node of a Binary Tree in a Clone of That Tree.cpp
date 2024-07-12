/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
   TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if (cloned==NULL) return NULL;
    if (cloned->val == target->val) return cloned;
    TreeNode* leftSearch = getTargetCopy(original, cloned->left, target);
    TreeNode* rightSearch = getTargetCopy(original, cloned->right, target);

    if (leftSearch != NULL) return leftSearch;
    else return rightSearch;
}
};
