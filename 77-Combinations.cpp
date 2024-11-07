class Solution {
public:
    void helper(vector<vector<int>>&res , vector<int> &current , int n , int k , int e){
        if(current.size() == k){
            res.push_back(current);
        }
        if(e > n) return;
        for(int i = e ; i <= n ; i++){
            current.push_back(i);
            helper(res , current , n , k , i + 1);
            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> current;
        helper(res , current , n , k , 1);
        return res;
    }
};