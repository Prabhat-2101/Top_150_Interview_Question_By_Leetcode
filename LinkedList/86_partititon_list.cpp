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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL or head->next==NULL) return head;
        ListNode* left=NULL,*right=NULL;
        ListNode* t1=left,*t2=right;
        while(head){
            int data = head->val;
            ListNode* newN = new ListNode(data);
            if(data < x){
                if(t1 == NULL) {
                    t1 = newN;
                    left = newN;
                }
                else {
                    t1->next = newN;
                    t1 = t1->next;
                }
            }else{
                if(t2 == NULL) {
                    t2 = newN;
                    right = newN;
                }
                else {
                    t2->next = newN;
                    t2 = t2->next;
                }
            }
            head = head->next;
        }
        if(t1) t1->next = right;
        else left = right;
        return left;
    }
};