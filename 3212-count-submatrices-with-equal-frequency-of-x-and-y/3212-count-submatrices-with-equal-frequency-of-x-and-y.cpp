class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;

        for (int top = 0; top < n; top++) {
            vector<int> countX(m, 0), countY(m, 0);

            for (int bottom = top; bottom < n; bottom++) {
                for (int col = 0; col < m; col++) {
                    if (grid[bottom][col] == 'X') countX[col]++;
                    if (grid[bottom][col] == 'Y') countY[col]++;
                }

                int diff = 0;
                unordered_map<int, int> mp;
                mp[0] = 1;

                for (int col = 0; col < m; col++) {
                    diff += countX[col] - countY[col];
                    ans += mp[diff];
                    mp[diff]++;
                }
            }
        }

        return ans;
    }
};