class Solution {
public:
    ListNode* rotateRight(ListNode* h, int k) {
        if(!h || !h->next || k == 0) return h;
        ListNode* t = h;
        int n = 1;
        while(t->next) {
            t = t->next;
            n++;
        }
        t->next = h;
        k %= n;
        int s = n - k;
        ListNode* cur = h;
        for(int i = 1; i < s; i++) cur = cur->next;
        ListNode* nh = cur->next;
        cur->next = NULL;
        return nh;
    }
};