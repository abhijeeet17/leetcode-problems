class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        string row = "12210111011122000010020202";
        for (string word : words) {
            int r = row[tolower(word[0]) - 'a'];
            bool ok = true;
            for (char c : word) {
                if (row[tolower(c) - 'a'] != r) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans.push_back(word);
        }
        return ans;
    }
};