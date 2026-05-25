class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int inc = true;
        int desc = true;
        for(int i =1; i<nums.size(); i++){
            if(nums[i-1]>nums[i]) inc =  false;
            if(nums[i-1]<nums[i]) desc =  false;
        }
        return inc || desc;
    }
};