class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

        unordered_map<int,int> mp;
        typedef pair<int,int> pi;

        for(int x : nums){
            mp[x]++;
        }

        auto cmp = [](pi a, pi b){
            if(a.first == b.first)
                return a.second < b.second; // larger number first
            return a.first > b.first;       // smaller frequency first
        };

        priority_queue<pi, vector<pi>, decltype(cmp)> pq(cmp);

        for(auto it : mp){
            pq.push({it.second, it.first});
        }

        vector<int> vec;

        while(!pq.empty()){
            int freq = pq.top().first;
            int num = pq.top().second;
            pq.pop();

            for(int i = 0; i < freq; i++){
                vec.push_back(num);
            }
        }

        return vec;
    }
};