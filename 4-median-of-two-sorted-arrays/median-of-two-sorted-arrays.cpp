class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        vector<int>mergedArray;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]<nums2[j])
            {
                mergedArray.push_back(nums1[i]);
                i++;
            }
            else
            {
                mergedArray.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size())
        {
            mergedArray.push_back(nums1[i]);
                i++;
        }
        while(j<nums2.size())
        {
            mergedArray.push_back(nums2[j]);
                j++;
        }

        int n=mergedArray.size();
        if(n%2!=0)
        {
            return mergedArray[n/2];
        }
        else
        {
            return( mergedArray[n/2]+mergedArray[(n/2)-1]) /2.00;
        }
    }
};