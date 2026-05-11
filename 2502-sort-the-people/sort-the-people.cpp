class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string>mp;
        for(int i = 0; i<names.size(); i++){
            mp[heights[i]] = names[i];
        }
        vector<string>vec;
        for(auto itr = mp.rbegin(); itr!= mp.rend(); itr++){
            vec.push_back(itr->second);
        }
return vec;
    }
};