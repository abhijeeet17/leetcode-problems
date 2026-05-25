class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> vec;
        map<int, int> mp;
        for (auto m : nums) {
            mp[m]++;
            if (mp[m] <= k) {
                vec.push_back(m);
            }
        }
        return vec;
    }
};