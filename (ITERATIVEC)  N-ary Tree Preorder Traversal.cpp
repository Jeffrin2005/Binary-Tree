class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        if(root == NULL) return result;  
    stack<Node*> stack;  
        stack.push(root);  // Start with the root node.
        while (!stack.empty()){
           auto node = stack.top();  // Get the top node from the stack.
            stack.pop();  
            result.push_back(node->val);  //  the current node by adding its value to the result.
            // Since the stack is LIFO and we need to process children from left to right,
            // we push children to the stack from right to left.
                        for (int i = node->children.size() - 1; i >= 0; i--){
                stack.push(node->children[i]);  // Push each child to the stack.
            }
//     1
//    /|\
//   2 3 4
//             stack = [1]
// result = []
// 2. Processing Node 1:
// Pop 1 from the stack.
// Add 1 to result: result = [1].
// Push its children 2, 3, 4 to the stack. Since we need to process children from left to right and the stack is LIFO, we push them in reverse order:
// Push 4, then 3, then 2.
// Now, stack = [4, 3, 2].
// 3. Processing Node 2:
// Pop 2 from the stack (it's the topmost).
// Add 2 to result: result = [1, 2]. etc ....... 
        }
        return result;  // Return the collected node values.
    }
};
