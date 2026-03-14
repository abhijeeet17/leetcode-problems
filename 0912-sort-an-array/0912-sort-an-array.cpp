class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int, vector<int>,greater<int>>pq;
        for(int i = 0;  i<n; i++){
            pq.push(nums[i]);
        }
        for(int i =  0; i<nums.size(); i++){
            nums[i] = pq.top();
            pq.pop();
        }
        return nums;
    }

};