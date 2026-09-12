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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        int length=0;
        while(temp!=NULL){
            length++;
            temp=temp->next;
        }
        k=k%length;
        while(k>0){
            ListNode* temp1=head;
            ListNode* prev=NULL;
            while(temp1->next != NULL){
                prev=temp1;
                temp1=temp1->next;
            }
            prev->next=NULL;
            temp1->next=head;
            head=temp1;
            k--;
        }
        return head;
    }
};