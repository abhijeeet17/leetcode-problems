class Solution {
public:
    int n;
    
    int solve(int i, vector<int>& arr, int d, vector<int>& dp) {
        if (dp[i] != -1)
            return dp[i];

        int ans = 1;
        for (int j = i - 1; j >= max(0, i - d); j--) {
            if (arr[j] >= arr[i])
                break;

            ans = max(ans, 1 + solve(j, arr, d, dp));
        }
        for (int j = i + 1; j <= min(n - 1, i + d); j++) {
            if (arr[j] >= arr[i])
                break;

            ans = max(ans, 1 + solve(j, arr, d, dp));
        }

        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();

        vector<int> dp(n, -1);

        int result = 1;

        for (int i = 0; i < n; i++) {
            result = max(result, solve(i, arr, d, dp));
        }

        return result;
    }
};