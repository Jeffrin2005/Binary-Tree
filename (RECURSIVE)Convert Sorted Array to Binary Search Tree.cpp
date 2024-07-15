/**
time complxity = o(n)
space compleixty = o(log(n))
 */
class Solution {
private:
    TreeNode* check(vector<int>&nums, int left, int right){
        if(left > right) {
            return NULL;
        }
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = check(nums, left, mid - 1);
        node->right = check(nums, mid + 1, right);
        return node; 
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return check(nums, 0, n - 1);

    }
};
