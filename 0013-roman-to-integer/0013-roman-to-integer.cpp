class Solution {
public:
    int romanToInt(string s) {
        static int val[128] = {0};
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;

        int n = s.size();
        int result = 0;

        for (int i = 0; i < n; ++i) {
            int curr = val[s[i]];
            int next = (i + 1 < n) ? val[s[i + 1]] : 0;

            if (curr < next)
                result -= curr;
            else
                result += curr;
        }

        return result;
    }
};
