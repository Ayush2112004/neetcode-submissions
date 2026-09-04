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
    ListNode* reverseList(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        ListNode* temp=head;
        while(left>1){
            curr->next=new ListNode(temp->val);
            curr=curr->next;
            left--;
            right--;
            temp=temp->next;
        }
        ListNode* dummyToRev=new ListNode(0);
        ListNode* curr2=dummyToRev;
        while(right>0){
            curr2->next=new ListNode(temp->val);
            curr2=curr2->next;
            right--;
            temp=temp->next;
        }
        ListNode* reversed=reverseList(dummyToRev->next);
        curr->next=reversed;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        while(temp!=NULL){
            curr->next=new ListNode(temp->val);
            curr=curr->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};