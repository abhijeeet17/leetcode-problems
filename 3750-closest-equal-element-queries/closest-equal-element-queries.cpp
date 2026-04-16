class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            auto &v = mp[nums[q]];

            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int idx = lower_bound(v.begin(), v.end(), q) - v.begin();

            int left = (idx - 1 + v.size()) % v.size();
            int right = (idx + 1) % v.size();

            int d1 = abs(q - v[left]);
            int d2 = abs(q - v[right]);

            d1 = min(d1, n - d1);
            d2 = min(d2, n - d2);

            ans.push_back(min(d1, d2));
        }

        return ans;
    }
};