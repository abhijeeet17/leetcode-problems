class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int total=0;
        for(int x:nums) total+=x;
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(l==total-l-nums[i]) return i;
            l+=nums[i];
        }
        return -1;
    }
};