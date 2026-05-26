class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(letters[mid]<= target){
                low = mid+1;
                // agar mid target se chhota ya equal hai
     // to right side me jaenge
            }
            // agar mid target se bada hai
                // to left side check karenge
            else{
            high = mid-1;
            }
        }
        return letters[low % letters.size()];
    }
};