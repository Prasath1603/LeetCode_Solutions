class Solution {
public:
    
    int robHelper(vector<int> &nums, int curr, int end,vector<int> &dp) {
        if (curr > end) return 0;

        if(dp[curr] != -1) return dp[curr];
        int pick = nums[curr] + robHelper(nums, curr + 2, end,dp);
        int notPick = robHelper(nums, curr + 1, end,dp);

        return dp[curr] =  max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; 
        if (n == 2) return max(nums[0], nums[1]);  

        vector<int > dp1(n , -1);
        int robFirst = robHelper(nums, 0, n - 2,dp1);
        vector<int > dp2(n , -1);
        int robLast = robHelper(nums, 1, n - 1,dp2);
        return max(robFirst, robLast);
    }
};
