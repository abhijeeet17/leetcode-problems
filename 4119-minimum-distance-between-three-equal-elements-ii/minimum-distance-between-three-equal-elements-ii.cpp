class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        // store indices
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for(auto &it : mp) {
            vector<int>& pos = it.second;

            // need at least 3 occurrences
            if(pos.size() < 3) continue;

            for(int i = 0; i + 2 < pos.size(); i++) {
                int dist = 2 * (pos[i+2] - pos[i]);
                ans = min(ans, dist);
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};