class Solution {
public:
    void powerSet(vector<vector<int>> &result,vector<int> &subset , int index , vector<int>& nums){
        result.push_back(subset);

        for(int i = index ; i < nums.size() ; i++){

            if(i > index && nums[i] == nums[i - 1]){
                continue;
            }

            subset.push_back(nums[i]);

            powerSet(result , subset , i + 1 , nums);

            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> result;
        vector<int> subset;
        powerSet(result, subset , 0 , nums);
        return result;
    }
};