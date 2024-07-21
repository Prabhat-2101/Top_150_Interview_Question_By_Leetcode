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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        if(count == 1)
            return NULL;61
        if(count == n)
            return head->next;
        temp = head;
        for(int i=1;i<count-n;i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};32