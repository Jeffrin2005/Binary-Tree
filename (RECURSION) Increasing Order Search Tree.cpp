//Time complexity: o(n) where n is the no of nodes
//Space complexity: o(log(n))
class Solution {
public:
    // Dummy node to start the new tree and pointer to track the last added node
    TreeNode* head = new TreeNode(0);
    TreeNode* ptr = head;

    // Recursive function to perform in-order traversal
    void in_order(TreeNode* root){
        if(root == NULL) return; // Base case: if the node is null, stop recursion

        in_order(root->left); // Recursively visit the left subtree

        // Process the current node:
        // 1. Create a new node with the current node's value
        // 2. Link it to the right of the last node in the new tree
        head->right = new TreeNode(root->val);
        head = head->right; // Move the head pointer to the new node

        in_order(root->right); // Recursively visit the right subtree
        return;
    }

    // Function to rearrange the BST into a right-skewed tree
    TreeNode* increasingBST(TreeNode* root) {
        in_order(root); // Start in-order traversal from the root
        return ptr->right; // Return the right child of the dummy node, which is the new root
    }
};
