
class Solution {
public:
    int level(TreeNode*root){
        if(root==NULL) return 0; 
        return 1+ max(level(root->left), level(root->right));
    }
    void nlevel(TreeNode*root, int level,int curr,vector<int>&v){
        if(root==NULL) return;
        if(curr==level){
            v.push_back(root->val);
            return;
        }
        nlevel(root->left,level,curr+1,v);
        nlevel(root->right,level, curr+1, v);
    }
    void nlevelprint(TreeNode*root,vector<vector<int>>&ans){
         int n = level(root);
         for(int i = 0; i<n; i++){
            vector<int>v;
            nlevel(root,i,0,v);
            ans.push_back(v);
            cout<<endl;
         }
    } 
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        nlevelprint(root,ans);
        return ans;
    }
};