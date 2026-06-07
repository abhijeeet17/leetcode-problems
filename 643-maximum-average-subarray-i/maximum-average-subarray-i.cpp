class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        for(int i =0; i<k; i++){
            sum+=nums[i];
        }
        int low = 0;
        int high = k;
        double res = sum;
        while(high< n){
            sum-=nums[low];
            low++;
            sum+=nums[high];
            res = max(sum,res);
            high++;
        }
        return (double)res/ k; 
    }
};