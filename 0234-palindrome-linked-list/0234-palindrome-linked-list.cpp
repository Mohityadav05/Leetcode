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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode* newhead=new ListNode(head->val);
        ListNode* oldtemp=head->next;
        ListNode* newtemp=newhead;
        while(oldtemp != NULL){
            ListNode* copynode=new ListNode(oldtemp->val);
            newtemp->next=copynode;
            oldtemp=oldtemp->next;
            newtemp=newtemp->next;
        }

        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(curr != NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        ListNode* temp1=prev;
        ListNode* temp2=newhead;
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val != temp2->val){
                return false;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return true;
    }
};