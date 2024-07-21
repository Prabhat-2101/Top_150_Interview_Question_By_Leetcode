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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newN = new ListNode(-1);
        newN->next = head;
        ListNode* temp = newN;
        while(head){
            if(head->next && head->val == head->next->val){
                while(head->next && head->val == head->next->val) head = head->next;
                temp->next = head->next;
            }else{
                temp = temp->next;
            }
            head = head->next;
        }
        return newN->next;
    }
};