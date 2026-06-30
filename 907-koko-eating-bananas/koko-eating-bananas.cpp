class Solution {
public:
    bool check(vector<int>& p, int h, int k) {
        long long t = 0;
        for (int x : p) {
            t += (x + k - 1) / k;
        }
        return t <= h;
    }
    int minEatingSpeed(vector<int>& p, int h) {
        int l = 1;
        int r = *max_element(p.begin(), p.end());

        while (l < r) {
            int m = l + (r - l) / 2;

            if (check(p, h, m))
                r = m;
            else
                l = m + 1;
        }

        return l;
    }
};