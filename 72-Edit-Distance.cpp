class Solution {
public:
    int minDistance(string word1, string word2) {
        int r = word1.size(), c = word2.size();
        vector<vector<int>>dp(r + 1 , vector<int>( c + 1 , 0));
        for(int i = 0 ; i < c + 1; i++) dp[0][i] = i;
        for(int i = 0 ; i < r + 1; i++) dp[i][0] = i;

        for(int i = 1 ; i < r + 1 ; i++){
            for(int j = 1 ; j < c + 1; j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = 0 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i][j - 1] , min(dp[i - 1][j] , dp[i - 1][j - 1]));
                }
            }
        }
        return dp[r][c];
    }
};