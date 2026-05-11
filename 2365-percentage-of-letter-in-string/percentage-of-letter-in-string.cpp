class Solution {
public:
    int percentageLetter(string s, char letter) {
        int length = s.length();
        int occur = 0;
        int res =0;

        for(int i = 0; i<length; i++){
        if(s[i] == letter){
            occur++;
           }
        
        }
        res = (100*occur)/length;
        return res;
    }
};