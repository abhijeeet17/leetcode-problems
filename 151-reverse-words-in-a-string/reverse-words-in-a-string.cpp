class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int l = 0;
        int r =0;
        int i = 0;
        reverse(s.begin(),s.end());
        while(i<n){
            while(i<n && s[i] != ' '){
                s[r] = s[i];
                r++;
                i++;
            }
            if(l<r){
                reverse(s.begin()+l,s.begin()+r);
                s[r] = ' ';
                r++;
                l =r;
            }
            i++;
        }
        return s.substr(0,r-1);
    }
};