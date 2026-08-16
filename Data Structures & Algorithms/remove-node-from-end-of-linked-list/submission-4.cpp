class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = head;
        ListNode* next = head;

        while(n > 0){
            next = next->next;
            n--;
        }

        // remove head
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