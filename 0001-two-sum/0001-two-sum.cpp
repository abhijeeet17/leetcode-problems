class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        unordered_map<int,int> m;
        for(int i = 0; i < a.size(); i++) {
            int x = t - a[i];
            if(m.count(x)) return {m[x], i};
            m[a[i]] = i;
        }
        return {};
    }
};