class Solution {
    class SparseTable {
    public:
        vector<vector<long long>> st;
        function<long long(long long, long long)> op;

        SparseTable(vector<int>& nums,
                    function<long long(long long, long long)> f) {
            op = f;
            int n = nums.size();
            int K = __lg(n);

            st.assign(K + 1, vector<long long>(n));

            for (int i = 0; i < n; i++)
                st[0][i] = nums[i];

            for (int k = 1; k <= K; k++) {
                for (int i = 0; i + (1 << k) <= n; i++) {
                    st[k][i] =
                        op(st[k - 1][i],
                           st[k - 1][i + (1 << (k - 1))]);
                }
            }
        }

        long long query(int L, int R) {
            int k = __lg(R - L + 1);
            return op(st[k][L],
                      st[k][R - (1 << k) + 1]);
        }
    };

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SparseTable mn(nums,
            [](long long a, long long b) {
                return min(a, b);
            });

        SparseTable mx(nums,
            [](long long a, long long b) {
                return max(a, b);
            });

        using Node = pair<long long, pair<int,int>>;
        priority_queue<Node> pq;

        for (int i = 0; i < n; i++) {
            long long val =
                mx.query(i, n - 1) -
                mn.query(i, n - 1);

            pq.push({val, {i, n - 1}});
        }

        long long ans = 0;

        while (k--) {
            auto [val, seg] = pq.top();
            pq.pop();

            auto [l, r] = seg;
            ans += val;

            if (l <= r - 1) {
                long long nxt =
                    mx.query(l, r - 1) -
                    mn.query(l, r - 1);

                pq.push({nxt, {l, r - 1}});
            }
        }

        return ans;
    }
};