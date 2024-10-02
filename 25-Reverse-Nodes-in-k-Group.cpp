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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* findKthNode(ListNode* head, int k) {
        int i = 0;
        while (i < k - 1 && head) {
            head = head->next;
            i++;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* newHead = nullptr;
        while(temp){
            ListNode* kNode = findKthNode(temp,k);
            if(kNode){
                ListNode* Next = kNode->next;
                kNode->next = nullptr;
                ListNode* reversed = reverse(temp);
                if(newHead==NULL){
                    newHead = reversed;
                }
                if(prev){
                    prev->next = reversed;
                }

                prev = temp;
                temp = Next;
            }
            else{
                if(prev){
                    prev->next = temp;
                }
                break;
            }
        }
        return newHead ? newHead : head;
    }
};