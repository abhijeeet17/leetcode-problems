class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>sorted=arr;
        sort(sorted.begin(),sorted.end());
        unordered_map<int,int>mp;

        int r=1;
        for(int x:sorted){
            if(!mp.count(x)){
                mp[x]=r;
                r++;
            }
        }

        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};