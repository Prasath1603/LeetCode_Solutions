class Solution {
public:
    int House(vector<int> &nums,int curr,vector<int>& dp){
        if(curr >= nums.size()) return 0;

        if(dp[curr] != -1) return dp[curr];
        int take = nums[curr] + House(nums, curr + 2,dp);
        int notTake = House(nums, curr + 1,dp);

        return dp[curr] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() , -1);
        return House(nums, 0, dp);
    }
};