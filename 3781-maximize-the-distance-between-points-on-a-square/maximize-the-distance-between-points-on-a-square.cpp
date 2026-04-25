class Solution {
public:
    bool can(vector<long long>& pos, int k, long long d, long long perimeter) {
        int n = pos.size();
        vector<long long> ext = pos;
        for (int i = 0; i < n; i++) {
            ext.push_back(pos[i] + perimeter);
        }

        for (int i = 0; i < n; i++) {
            int count = 1;
            long long first = ext[i];
            long long last = ext[i];
            int idx = i;

            while (count < k) {
                int next = lower_bound(ext.begin() + idx + 1,
                                       ext.begin() + i + n,
                                       last + d) - ext.begin();

                if (next == i + n) break;

                last = ext[next];
                idx = next;
                count++;
            }
            if (count == k && first + perimeter - last >= d)
                return true;
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> pos;
        for (auto &p : points) {
            long long x = p[0], y = p[1];

            if (y == 0) pos.push_back(x);                      
            else if (x == side) pos.push_back(side + y);        
            else if (y == side) pos.push_back(3LL * side - x);  
            else pos.push_back(4LL * side - y);                  
        }

        sort(pos.begin(), pos.end());

        long long perimeter = 4LL * side;
        long long low = 0, high = perimeter, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (can(pos, k, mid, perimeter)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};