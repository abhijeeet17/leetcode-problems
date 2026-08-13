class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (int num : nums) {
            arr.push_back(to_string(num));
        }
        auto mycomp = [](const string &s1,const string &s2){
            if(s1+s2 > s2+s1){
                return true;
            }
            else{
                return false;
            }
        };
        sort(arr.begin(),arr.end(),mycomp);
        string ans;
        if(arr[0] == "0") return "0";
        for(string  &s : arr){ 
            ans+=s;
        }
        return ans;
    }
};