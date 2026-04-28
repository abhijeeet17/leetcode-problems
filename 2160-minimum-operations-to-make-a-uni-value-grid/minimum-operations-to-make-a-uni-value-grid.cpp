class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        
        for (auto &row : grid) {
            for (auto &val : row) {
                arr.push_back(val);
            }
        }
        
        int rem = arr[0] % x;
        for (int num : arr) {
            if (num % x != rem) return -1;
        }
        
        sort(arr.begin(), arr.end());
        
        int median = arr[arr.size() / 2];
        
        int ops = 0;
        for (int num : arr) {
            ops += abs(num - median) / x;
        }
        
        return ops;
    }
};