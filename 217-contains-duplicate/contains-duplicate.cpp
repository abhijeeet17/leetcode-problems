class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto m: nums){
            mp[m]++;
            if(mp[m]>1)
            return true;
        }
        return false;
    }
};