class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];  // initialize
        
        for(int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            while(left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // Update closest sum if this is nearer to target
                if(abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                }
                
                if(currentSum < target) {
                    left++;      // need larger sum
                }
                else if(currentSum > target) {
                    right--;     // need smaller sum
                }
                else {
                    return currentSum; // exact match found
                }
            }
        }
        
        return closestSum;
    }
};
