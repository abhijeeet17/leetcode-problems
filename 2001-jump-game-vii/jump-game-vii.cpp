class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;

        int farthest = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == n - 1)
                return true;

            int start = max(curr + minJump, farthest + 1);
            int end = min(curr + maxJump, n - 1);

            for (int i = start; i <= end; i++) {
                if (s[i] == '0' && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }

            farthest = end;
        }

        return false;
    }
};