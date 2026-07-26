class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int x : nums) {
            if (x % 2 == 0)
                mp[x]++;
        }

        int ans = -1;

        for (auto it : mp) {
            if (ans == -1 ||
                it.second > mp[ans] ||
                (it.second == mp[ans] && it.first < ans)) {
                ans = it.first;
            }
        }

        return ans;
    }
};