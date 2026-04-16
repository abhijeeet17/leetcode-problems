class Solution {
public:

    bool isMirror(TreeNode* left, TreeNode* right) {
        // दोनों NULL
        if (left == NULL && right == NULL) return true;

        // एक NULL, एक नहीं
        if (left == NULL || right == NULL) return false;

        // value check + recursive mirror check
        return (left->val == right->val) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;

        return isMirror(root->left, root->right);
    }
};