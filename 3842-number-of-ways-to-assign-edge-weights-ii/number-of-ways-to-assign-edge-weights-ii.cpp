class Solution {
public:
    const int MOD = 1e9 + 7;
    int LOG = 20;

    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;
    vector<long long> pow2;

    void dfs(int node, int parent) {
        up[node][0] = parent;

        for (int i = 1; i < LOG; i++) {
            if (up[node][i - 1] != -1)
                up[node][i] = up[up[node][i - 1]][i - 1];
            else
                up[node][i] = -1;
        }

        for (int nxt : adj[node]) {
            if (nxt == parent) continue;
            depth[nxt] = depth[node] + 1;
            dfs(nxt, node);
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int i = LOG - 1; i >= 0; i--) {
            if ((diff >> i) & 1)
                u = up[u][i];
        }

        if (u == v) return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        adj.resize(n + 1);
        depth.resize(n + 1);
        up.assign(n + 1, vector<int>(LOG, -1));

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, -1);

        // Precompute powers of 2
        pow2.resize(n + 1);
        pow2[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0], v = q[1];

            int ancestor = lca(u, v);

            int edgesCount =
                depth[u] + depth[v] - 2 * depth[ancestor];

            if (edgesCount == 0)
                ans.push_back(0);
            else
                ans.push_back(pow2[edgesCount - 1]);
        }

        return ans;
    }
};