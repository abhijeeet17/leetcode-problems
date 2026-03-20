class Solution {
public:
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        ListNode* d = new ListNode(0);
        ListNode* cur = d;
        int c = 0;

        while(a || b || c) {
            int s = c;
            if(a) { s += a->val; a = a->next; }
            if(b) { s += b->val; b = b->next; }

            c = s / 10;
            cur->next = new ListNode(s % 10);
            cur = cur->next;
        }

        return d->next;
    }
};