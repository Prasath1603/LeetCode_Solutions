class Solution {
public:
    void powerSet(vector<vector<int>> &result,vector<int> &subset , int index , vector<int>& nums){

        result.push_back(subset);

        for(int i = index ; i < nums.size() ; i++){

            subset.push_back(nums[i]);

            powerSet(result , subset , i + 1 , nums);

            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        powerSet(result, subset , 0 , nums);
        return result;
    }
};