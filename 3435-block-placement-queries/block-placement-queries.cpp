class Solution {
public:
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void update(int idx, int val) {
            for (++idx; idx <= n; idx += idx & -idx)
                bit[idx] = max(bit[idx], val);
        }

        int query(int idx) {
            int res = 0;
            for (++idx; idx > 0; idx -= idx & -idx)
                res = max(res, bit[idx]);
            return res;
        }
    };

    vector<bool> getResults(vector<vector<int>>& queries) {
        int MX = 50000;

        set<int> pos = {0, MX};

        vector<int> inserted;

        for (auto &q : queries)
            if (q[0] == 1)
                inserted.push_back(q[1]);

        for (int x : inserted)
            pos.insert(x);

        Fenwick bit(MX + 2);

        vector<int> all(pos.begin(), pos.end());

        for (int i = 1; i < all.size(); i++)
            bit.update(all[i], all[i] - all[i - 1]);

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {
            auto &q = queries[i];

            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];

                auto it = pos.upper_bound(x);
                int r = *it;
                --it;
                int l = *it;

                int best = max(bit.query(l), x - l);

                ans.push_back(best >= sz);
            } else {
                int x = q[1];

                auto it = pos.find(x);

                auto prv = prev(it);
                auto nxt = next(it);

                bit.update(*nxt, *nxt - *prv);

                pos.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};