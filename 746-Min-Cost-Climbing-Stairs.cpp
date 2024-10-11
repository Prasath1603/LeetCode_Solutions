class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size());
        for(int i = 0 ; i < cost.size() ; i++){
            dp[i] = cost[i];
        }
        for(int i = cost.size() - 3; i > -1 ; i--){
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        }
        return min(dp[0],dp[1]);
    }
};