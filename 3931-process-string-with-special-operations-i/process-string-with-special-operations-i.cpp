class Solution {
public:
    string processStr(string s) {
        string str;
        for(char c: s){
            switch(c){
                case '*':
                    if(!str.empty()) str.pop_back();
                    break;
                case '#':
                    str+=str;
                    break;
                case '%':
                    reverse(str.begin(), str.end());
                    break;
                default:
                    str.push_back(c);
            }
        }
        return str;
    }
};