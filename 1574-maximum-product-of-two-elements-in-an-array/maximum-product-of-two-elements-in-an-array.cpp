class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int largest = nums[n-1];
        int slargest = nums[n-2];
        return (largest-1) * (slargest-1);
    }
};