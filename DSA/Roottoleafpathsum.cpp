class Solution {
  public:
    bool hasPathSum(Node *root, int target) {
        // Your code here
        return root ? root->left == root->right ? target==root->data : hasPathSum(root->left, target-root->data) || hasPathSum(root->right, target-root->data) : false;
    }
};
