class Solution {
public:
    ListNode* partition(ListNode* h, int x) {
        ListNode a(0), b(0);
        ListNode *p = &a, *q = &b;
        while (h) {
            if (h->val < x) {
                p->next = h;
                p = p->next;
            } else {
                q->next = h;
                q = q->next;
            }
            h = h->next;
        }
        q->next = nullptr;
        p->next = b.next;

        
        return a.next;
    }
};