class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val) {
            ListNode* del = head;
            head = head->next; 
            delete del;       
        }
        if (head == NULL) return NULL;
        ListNode* prev = head;
        ListNode* temp = head->next;
        while (temp != NULL) {
            if (temp->val == val) {
                ListNode* del = temp;
                prev->next = temp->next;  
                temp = temp->next;       
                delete del;               
            } else {
                prev = temp;            
                temp = temp->next;        
            }
        }
        return head; 
    }
};
