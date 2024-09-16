
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        queue<TreeNode*>nodeQueue;
        nodeQueue.push(root);
        bool leftToRight = true;
        while(!nodeQueue.empty()){
            int levelSize = nodeQueue.size();
           vector<int>currentLevel(levelSize);
            for (int i = 0; i < levelSize; i++){
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                // Determine the position to fill the node's value
                int index = leftToRight ? i : (levelSize - 1 - i);// i means left and other is right 
                currentLevel[index] = currentNode->val;
                // Enqueue child nodes for the next level
                if (currentNode->left){
                    nodeQueue.push(currentNode->left);
                } if (currentNode->right){
                    nodeQueue.push(currentNode->right);
                }
            }

            // After processing the current level, toggle the traversal direction
            leftToRight = !leftToRight;
            result.push_back(currentLevel);
        }

        return result;
    }
};
