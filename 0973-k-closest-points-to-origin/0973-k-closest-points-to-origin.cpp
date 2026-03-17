class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for(auto &p : arr){
            int x = p[0];
            int y = p[1];
            int dist = x*x + y*y;
            pq.push({dist,p});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>>vec;
        while(!pq.empty()){
            vec.push_back(pq.top().second);
            pq.pop();
        }
        return vec;
    }
};