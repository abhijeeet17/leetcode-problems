class Solution {
public:
    int maxdia = 0;
    int level(TreeNode*root){
        if(root==NULL) return 0;
        return 1+ max(level(root->left) , level(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int dia = level(root->left) + level(root->right);
        maxdia = max(maxdia,dia);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
    return maxdia;
    }
};