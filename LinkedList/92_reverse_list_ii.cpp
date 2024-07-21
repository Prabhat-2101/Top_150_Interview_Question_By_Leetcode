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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left>=right) return head;
        ListNode* dummy = new ListNode(-1,head);
        ListNode* curr = head, *lp = dummy;
        for(int i=0;i<left-1;i++){
            lp = curr;
            curr = curr->next;
        }
        ListNode* prev = NULL;
        for(int i=0;i<right-left+1;i++){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        lp->next->next = curr;
        lp->next = prev;
        return dummy->next;
    }
};