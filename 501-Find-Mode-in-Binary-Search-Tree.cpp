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
    map<int,int> mp;
    void inorder(TreeNode *root){
        if(root){
            inorder(root->left);
            mp[root->val]+=1;
            inorder(root->right);
        }
    }
    vector<int> findMode(TreeNode* root) {
    
        inorder(root);
        vector<int> res;
        // for(auto & i : mp){
        //     cout<< i.first<< \ \<< i.second<<endl;
        // }
        // cout<<endl;
        int maxx = -1;
        for(auto & i : mp){
            maxx = max(maxx, i.second);
        }
        // cout<<maxx;
        for(auto & i : mp){
            if(i.second == maxx){ res.push_back(i.first);}
        }
        return res;
    }
};