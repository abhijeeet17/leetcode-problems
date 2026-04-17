class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i], rev = 0;

            while (x > 0) {
                rev = rev * 10 + x % 10;
                x /= 10;
            }

            if (mp.find(nums[i]) != mp.end()) {
                ans = min(ans, i - mp[nums[i]]);
            }

            mp[rev] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};