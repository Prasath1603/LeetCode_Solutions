class Solution {
public:
    bool check(vector<vector<int>>& freq, int k, int j) {
        int temp;

        int prev = -1;
        for (int i = 0; i < 26; i++) {
            temp = freq[i][j] - (k > 0 ? freq[i][k - 1] : 0);
            if (temp > 0){
                if(prev == -1) prev = temp;
                else{
                    if(prev == temp) continue;
                    else return 0;
                }
            }
        }
        return 1;
    }

    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        if (n <= 0)
            return 0;
        vector<vector<int>> freq(26, vector<int>(n, 0));
        vector<int> dp(n, INT_MAX);
        dp[0] = 1;
        freq[s[0] - 'a'][0] += 1;

        for (int j = 1; j < n; j++) {
            freq[s[j] - 'a'][j] += 1;
            for (int i = 0; i < 26; i++)
                freq[i][j] += freq[i][j - 1];
        }
        // for (auto i : freq) {
        //     for (auto j : i)
        //         cout << j << ' ';
        //     cout << endl;
        // }
        // cout << endl;
        for (int j = 0; j < n; j++) {
            for (int k = j; k >= 0; k--) { 
                if (check(freq, k, j)) {  
                    dp[j] = min(dp[j], (k > 0 ? dp[k - 1] : 0) + 1);
                }
            }
        }

        // for (auto i : dp)
        //     cout << i << ' ';
        return dp[n - 1];
    }
};