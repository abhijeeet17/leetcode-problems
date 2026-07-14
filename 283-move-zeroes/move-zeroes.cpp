class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        for(int i = 0; i< n; i++){
            if(nums[i]!=0){
                nums[j] =nums[i];
                j++;
            }
        }
        while(j<n){
            nums[j] = 0;
            j++;
        }
    }
};