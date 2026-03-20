class Solution {
public:
    void f(int i, vector<int>& a, int t, vector<int>& v, vector<vector<int>>& ans) {
        if(t == 0) {
            ans.push_back(v);
            return;
        }
        if(i >= a.size() || t < 0) return;
        
        // pick
        v.push_back(a[i]);
        f(i, a, t - a[i], v, ans); // same index (reuse allowed)
        v.pop_back();
        
        // not pick
        f(i + 1, a, t, v, ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        vector<vector<int>> ans;
        vector<int> v;
        f(0, a, t, v, ans);
        return ans;
    }
};