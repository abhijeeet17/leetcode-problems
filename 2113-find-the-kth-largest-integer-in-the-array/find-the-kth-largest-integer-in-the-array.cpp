class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        auto mycomp = [](string a,string b){
            if(a.size() != b.size()){
                return a.size() > b.size();
            }
            else{
                return a>b;
            }
        };
       sort(nums.begin(),nums.end(),mycomp);
       return nums[k-1]; 
    }
};