class Solution {
public:
    int eggDrop(int e , int f , vector<vector<int>> &dp){
        if(f == 0 || f == 1) return f;
        if(e == 1) return f;

        if(dp[e][f] != -1) return dp[e][f];
        int minDrop = INT_MAX;
        int low = 1 , high = f;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int Break = eggDrop(e - 1 , mid - 1 , dp);
            int notBreak = eggDrop(e , f - mid , dp);
            int worstCase = 1 + max(Break , notBreak);

            minDrop = min(minDrop , worstCase);

            if(Break > notBreak) high = mid - 1;
            else low = mid + 1;
        }

        return dp[e][f] = minDrop;
    }
    int twoEggDrop(int f) {
        vector<vector<int>> dp(3 , vector<int> ( f + 1 , -1));
        return eggDrop(2 , f , dp);
    }
};