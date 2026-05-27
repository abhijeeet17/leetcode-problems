class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> ll(26, -1);
        vector<int> fu(26, -1);
        for(int i =0;i <word.size(); i++)
         {

            char ch = word[i];
            if(islower(ch)){
                ll[ch-'a'] =i;
            }
            else 
            {
                if(fu[ch -'A'] == -1) {
                    fu[ch- 'A'] = i;
                }
            }
        }int c = 0;
        for(int i = 0; i< 26;i++) {
            if(ll[i] != -1 && fu[i] != -1 && ll[i] < fu[i]) {
                c++;
            }
        }return c;
    }
};