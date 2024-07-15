class Solution {
private:
    void calculateSumsAndCounts(TreeNode* node, int level, vector<double>& sums, vector<int>& counts) {
        if (node == NULL){
            return;
        }
        // Ensure the vectors are large enough to hold the current level
        if (level >= sums.size()){
           //  If level >= sums.size() is true, it means the vectors do not have an index for the current level,
           // so elements are added to sums and counts to extend their size. This is typically done by appending a 0 to each vector, 
           //which then gets updated with the current node's value and count.
            sums.push_back(0); // Initialize sum for this level
            counts.push_back(0); // Initialize count for this level
            // [3, 0, 0 ]
        }

        // Add the current node's value to the sum of its level
        sums[level] += node->val;
        counts[level]++;
        //sums = [3, 29, 22]
        //counts = [1, 2, 2]   ->   [3.0  ,14.5 ,11.0]
        // Recurse to the left and right children
        calculateSumsAndCounts(node->left, level + 1, sums, counts);
        calculateSumsAndCounts(node->right, level + 1, sums, counts);
    }

public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sums; // To store the sum of values at each level
        vector<int>counts; // To store the number of nodes at each level
        vector<double>averages; // To store the final averages of each level
        calculateSumsAndCounts(root, 0, sums, counts);
        // Calculate the average for each level
        for (int i = 0; i < sums.size(); i++) {
            averages.push_back(sums[i] / counts[i]);
        }

        return averages;
    }
};
