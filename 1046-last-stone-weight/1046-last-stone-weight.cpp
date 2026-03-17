class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
        priority_queue<int>pq;
        for(int num  : arr){
            pq.push(num);
        }
        while(pq.size()>1){       
            int x = pq.top();
            pq.pop();
            int y =  pq.top();
            pq.pop();
            int final = abs(x-y);
            pq.push(final);
        }
        return pq.empty() ? 0:  pq.top();
    }
};