class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
          if(head == NULL) return nullptr;
        // Find the middle node of the list
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // Disconnect the left half from the middle node
        if(prev != NULL){
            prev->next = NULL;
        }
        // The middle node becomes the root
        TreeNode* root = new TreeNode(slow->val);
        // Base case when there is only one element in the list
        if(head == slow){
            return root;
        }
        // Recursively build the left and right subtrees
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};
