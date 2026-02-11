class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[256];
        memset(last, -1, sizeof(last));

        int left = 0;
        int maxLen = 0;
        int n = s.length();

        for (int right = 0; right < n; ++right) {
            unsigned char c = s[right];

            if (last[c] >= left)
                left = last[c] + 1;

            last[c] = right;

            int window = right - left + 1;
            if (window > maxLen)
                maxLen = window;
        }

        return maxLen;
    }
};
