class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> arr;
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }
        int l = 0;
        int r = arr.size() - 1;
        int maxi = 0;
        while (l < r) {
            maxi = max(maxi, arr[l] + arr[r]);
            l++;
            r--;
        }
        return maxi;
    }
};