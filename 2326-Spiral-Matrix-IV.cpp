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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int i, j;
        vector<vector<int>> v(m, vector<int>(n, -1));
        ListNode* t = head;
        int top = 0, bottom = m - 1, left = 0, right = n - 1, d = 0;
        while (top <= bottom && left <= right && t != NULL) {
            if (d == 0) {
                for (i = left; i <= right && t != NULL; i++) {
                    v[top][i] = t->val;
                    t = t->next;
                }
                top++;
            }
            if (d == 1) {
                for (i = top; i <= bottom && t != NULL; i++) {
                    v[i][right] = t->val;
                    t = t->next;
                }
                right--;
            }
            if (d == 2) {
                for (i = right; i >= left && t != NULL; i--) {
                    v[bottom][i] = t->val;
                    t = t->next;
                }
                bottom--;
            }
            if (d == 3) {
                for (i = bottom; i >= top && t != NULL; i--) {
                    v[i][left] = t->val;
                    t = t->next;
                }
                left++;
            }
            d = (d + 1) % 4;
        }
        // for (const auto& k : v) {
        //     for (int l : k) {
        //         cout << l << " ";
        //     }
        //     cout << endl;
        // }

        return v;
    }
};