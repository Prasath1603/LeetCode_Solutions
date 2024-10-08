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
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        if(n == 1) return head;
        int index = n / 2;
        temp = head->next;
        ListNode* prev = head;
        for(int i = 0 ; i < index - 1 ; i++){
            prev = temp;
            temp = temp->next;
        }
        return prev->next;
    }
};