class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int a = nums[0];
        int b = nums[0];
        for (int i = 0; i < n; i++) {
            if (a > nums[i])
                a = nums[i];
            if(b < nums[i]) b = nums[i];
        }
        while( b!=0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};