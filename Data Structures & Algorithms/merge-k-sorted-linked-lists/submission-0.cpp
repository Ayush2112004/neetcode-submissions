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
    struct cmp{
        bool operator()(ListNode* a,ListNode* b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        int n=lists.size();
        for(int i=0;i<n;i++){
            ListNode* curr=lists[i];
            while(curr!=NULL){
                pq.push(curr);
                curr=curr->next;
            }
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        while(!pq.empty()){
            ListNode* node=pq.top();
            pq.pop();
            tail->next=node;
            tail=tail->next;
        }
        tail->next=NULL;
        dummy=dummy->next;
        return dummy;
    }
};
