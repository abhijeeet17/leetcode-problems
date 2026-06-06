class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int left=0,right=0;
            for(int j=0;j<i;j++) left+=nums[j];
            for(int j=i+1;j<nums.size();j++) right+=nums[j];
            ans.push_back(abs(left-right));
        }
        return ans;
    }
};