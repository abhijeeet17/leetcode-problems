class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        vector<pair<char, int>> chars;

        for (auto &p : freq) {
            chars.push_back({p.first, p.second});
        }

        sort(chars.begin(), chars.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        string ans;

        for (auto &p : chars) {
            ans.append(p.second, p.first);
        }

        return ans;
    }
};