class Solution {
public:

    vector<int> spf;

    void buildSPF(int mx) {
        spf.resize(mx + 1);

        for (int i = 0; i <= mx; i++) {
            spf[i] = i;
        }

        for (int i = 2; i * i <= mx; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= mx; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    bool isPrime(int x) {
        return x >= 2 && spf[x] == x;
    }

    vector<int> getPrimeFactors(int x) {
        vector<int> factors;

        while (x > 1) {
            int p = spf[x];
            factors.push_back(p);

            while (x % p == 0) {
                x /= p;
            }
        }

        return factors;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        int mx = *max_element(nums.begin(), nums.end());

        buildSPF(mx);

        unordered_map<int, vector<int>> mp;

        // store indices divisible by prime p
        for (int i = 0; i < n; i++) {

            vector<int> factors = getPrimeFactors(nums[i]);

            for (int p : factors) {
                mp[p].push_back(i);
            }
        }

        queue<int> q;
        vector<int> vis(n, 0);

        q.push(0);
        vis[0] = 1;

        int steps = 0;

        unordered_set<int> usedPrime;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                int idx = q.front();
                q.pop();

                if (idx == n - 1) {
                    return steps;
                }

                // left
                if (idx - 1 >= 0 && !vis[idx - 1]) {
                    vis[idx - 1] = 1;
                    q.push(idx - 1);
                }

                // right
                if (idx + 1 < n && !vis[idx + 1]) {
                    vis[idx + 1] = 1;
                    q.push(idx + 1);
                }

                int val = nums[idx];

                if (isPrime(val) && !usedPrime.count(val)) {

                    for (int nextIdx : mp[val]) {

                        if (!vis[nextIdx]) {
                            vis[nextIdx] = 1;
                            q.push(nextIdx);
                        }
                    }

                    usedPrime.insert(val);
                }
            }

            steps++;
        }

        return -1;
    }
};