class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int num : nums){
            mp[num]++;
        }
        int maxx = INT_MIN;
        for(auto it: mp){
            if(it.second>maxx){
                maxx=it.second;
            }
        }
        int ans=0;
        for(auto it: mp){
            if (it.second==maxx){
                ans+=it.second;
            }
        }
        return ans;
    }
};