class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total=0,left=0;
        for(int x:nums) total+=x;
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            total-=nums[i];
            ans[i]=abs(left-total);
            left+=nums[i];
        }
        return ans;
    }
};