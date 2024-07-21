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
    int size_of_list(ListNode* head){
        int len=0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            len += 1;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = size_of_list(head);
        if(len<k) return head;
        int count = 0;
        ListNode* prev = NULL, *curr=head;
        while(count < k){
            ListNode* nxtNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxtNode;
            count += 1;
        }
        if(curr){
            ListNode* recursivePart = reverseKGroup(curr,k);
            head->next = recursivePart;
        }
        return prev;
    }
};