/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        int len = 0;
        ListNode*temp = head;
        while(temp != nullptr){
            len++;
            temp = temp->next;
        }
        //want to delete head
        if(len == n){
            ListNode*newhead = head->next;
            delete head;
            return newhead;
        }
        temp = head;
        for(int i = 1; i<len-n; i++){
            temp = temp->next;
        }
        ListNode*del = temp->next;
        temp->next = del->next;
        delete del;
        return head;
    }
};