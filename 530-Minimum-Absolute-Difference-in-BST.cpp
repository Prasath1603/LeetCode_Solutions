/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    void inorder(TreeNode* root){
        if(root != NULL){
            inorder(root->left);
            v.push_back(root->val);
            inorder(root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int n = v.size(), res = INT_MAX;
        for(int i = n - 1 ; i > 0 ; i--){
            res = min(res,abs(v[i] - v[i - 1]));
        }
        return res;
    }
};