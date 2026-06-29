class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int mx = INT_MIN;
        for(auto &p:mp)
        {
            mx = max(p.second, mx);
        }
        int count = 0;
        for(auto &p:mp)
        {
            if(p.second==mx)count+=p.second;
        }
        return count;
    }
};