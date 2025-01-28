class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> matrix(n + 1 , vector<int>(n + 1 , 0));
        for(auto t : trust){
            matrix[t[0]][t[1]] = 1;
        }
        vector<int> rowSum(n + 1 , 0) , colSum(n + 1 , 0);
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(matrix[i][j]){
                    rowSum[i]++;
                    colSum[j]++;
                }
            }
        }
        for(int i = 1 ; i <= n ; i++){
            if(colSum[i] == n - 1 && rowSum[i] == 0) return i;
        }
        return -1;
    }
};