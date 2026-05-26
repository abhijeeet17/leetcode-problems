class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        vector<int>res;
        for(int i = 0 ; i< n; i++){
            mp[nums[i]]++;
        }
        for(auto m:mp){
            if(m.second>1){
                res.push_back(m.first);
            }
        }
        return res;
    }
};