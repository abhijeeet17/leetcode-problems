class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size()-1;
        int n = numbers.size();
        int sum = 0;
        int i=0;
        for(int j = 0; j<n; j++){
            sum = numbers[low] + numbers[high];
            if(sum == target) return {low+1,high+1};
            if(sum<target) low++;
            else{
                high--;
            }
        }
        return {};
    }
};