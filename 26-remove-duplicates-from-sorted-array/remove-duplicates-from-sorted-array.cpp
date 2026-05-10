class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int low = 0;
        int high = 1;
        int n = nums.size();
        vector<int>ans;
        ans.push_back(nums[low]);
        while(high<n){
            if(nums[high]!=nums[low]){
                ans.push_back(nums[high]);
                low= high;
            }
            high++;
        }
        for(int i = 0; i<ans.size(); i++){
            nums[i] = ans[i];
        }
        return ans.size();
    }
};