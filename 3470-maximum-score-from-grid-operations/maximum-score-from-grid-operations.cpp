class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<long long>> pref(n, vector<long long>(n + 1, 0));
        
        for (int col = 0; col < n; ++col) {
            for (int r = 0; r < n; ++r) {
                pref[col][r + 1] = pref[col][r] + grid[r][col];
            }
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
        for (int c = 0; c <= n; ++c) {
            dp[0][c] = 0;
        }

        for (int j = 0; j < n - 1; ++j) {
            vector<vector<long long>> next_dp(n + 1, vector<long long>(n + 1, -1));

            for (int c = 0; c <= n; ++c) {
                vector<long long> best_m(n + 1, -1);
                for (int p = 0; p <= n; ++p) {
                    if (dp[p][c] != -1) {
                        int m = max(c, p);
                        best_m[m] = max(best_m[m], dp[p][c]);
                    }
                }

                vector<long long> pref_max(n + 1, -1);
                long long curr_max = -1;
                for (int m = c; m <= n; ++m) {
                    if (best_m[m] != -1) {
                        curr_max = max(curr_max, best_m[m] - pref[j][m]);
                    }
                    pref_max[m] = curr_max;
                }

                vector<long long> suff_max(n + 2, -1);
                curr_max = -1;
                for (int m = n; m >= c; --m) {
                    if (best_m[m] != -1) {
                        curr_max = max(curr_max, best_m[m]);
                    }
                    suff_max[m] = curr_max;
                }

                for (int n_c = 0; n_c <= n; ++n_c) {
                    long long t1 = (c > n_c) ? (pref[j + 1][c] - pref[j + 1][n_c]) : 0;
                    long long best_for_nc = -1;

                    if (n_c > c && pref_max[n_c - 1] != -1) {
                        best_for_nc = max(best_for_nc, pref_max[n_c - 1] + pref[j][n_c]);
                    }

                    int start_m = max(c, n_c);
                    if (suff_max[start_m] != -1) {
                        best_for_nc = max(best_for_nc, suff_max[start_m]);
                    }

                    if (best_for_nc != -1) {
                        next_dp[c][n_c] = max(next_dp[c][n_c], best_for_nc + t1);
                    }
                }
            }
            dp = next_dp;
        }

        long long ans = 0;
        for (int p = 0; p <= n; ++p) {
            for (int c = 0; c <= n; ++c) {
                ans = max(ans, dp[p][c]);
            }
        }

        return ans;
    }
};