class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>map;
        for(auto num : nums){
            map[num]++;
        }
        sort(nums.begin(),nums.end() ,[&](int first, int sec){
            if(map[first] != map[sec]) return map[first] < map[sec];
            return first> sec;
        });
        return nums;
    }

};