class Solution {
public:
    void dfs(TreeNode* root, int depth, vector<vector<int>>& ans) {
        if (!root) return;

        if (depth == ans.size())
            ans.push_back(vector<int>());

        ans[depth].push_back(root->val);

        dfs(root->left, depth + 1, ans);
        dfs(root->right, depth + 1, ans);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        return ans;
    }
};