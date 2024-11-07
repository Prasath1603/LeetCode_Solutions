class Solution {
public:
    void helper(vector<vector<int>>& res , vector<int> &current, vector<int> &candidates ,int index , int target , int n,int csum){
        if(csum == target){
            res.push_back(current);
            return;
        }
        if(csum > target) return;

        while(index < n){
            current.push_back(candidates[index]);
            helper(res , current , candidates , index , target , n , csum + candidates[index]);
            current.pop_back();
            index++;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> current;
        helper(res , current , candidates , 0 , target , candidates.size(), 0);
        return res;
    }
};