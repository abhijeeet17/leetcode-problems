class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*nextptr = NULL;
        ListNode*prev = NULL;
        ListNode*curr = head;
        while(curr!=nullptr){
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }
        return prev;
    }
};