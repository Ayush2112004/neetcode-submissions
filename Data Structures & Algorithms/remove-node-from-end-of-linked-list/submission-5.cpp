class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = head;
        ListNode* next = head;

        while(n > 0){
            next = next->next;
            n--;
        }//from this we have created the gap between the next and prev of n so that when the n will at the end the prev will point the node which we have to remove from the list

        if(next == NULL){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        while(next->next != NULL){
            next = next->next;
            prev = prev->next;
        }

        ListNode* temp = prev->next;
        prev->next = prev->next->next;
        delete temp;

        return head;
    }
};