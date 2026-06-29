class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;

        while(left <= right){
            int mid = left + (right-left)/2;
            int guessnum = guess(mid);

            if(guessnum == 0){
                return mid;
            }
            else if(guessnum == -1){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return -1;
    }
};