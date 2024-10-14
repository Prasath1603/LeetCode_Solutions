/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    
    int bfs(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int sum = 0;
        while (!q.empty()) {
            auto i = q.front();
            q.pop();
            if(i.first == nullptr) continue;
            if (i.second == 0) {
                if (i.first->left == nullptr && i.first->right == nullptr) {
                    sum += i.first->val;
                    continue;
                }
            }
            if (i.first->left != nullptr)
                q.push({i.first->left, 0});
            if (i.first->right != nullptr)
                q.push({i.first->right, 1});
        }
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr ||( root->left == nullptr && root->right == nullptr))
            return 0;
        return bfs(root);
        
    }
};