class Solution {
public:
    void powerSet(vector<vector<int>> &result,vector<int> &subset , int index , vector<int>& nums){

        if(index == nums.size()){
            result.push_back(subset);
            return;
        }
        
        powerSet(result , subset , index + 1 , nums);
        subset.push_back(nums[index]);

        powerSet(result , subset , index + 1 , nums);
        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        powerSet(result, subset , 0 , nums);
        return result;
    }
};