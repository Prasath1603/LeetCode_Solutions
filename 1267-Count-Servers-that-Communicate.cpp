class Solution {
public:

    int countServers(vector<vector<int>>& grid) {
        int count = 0, r = grid.size(), c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    int flag = 1;
                    for(int k = 0 ; k < c ; k++){
                        if(grid[i][k] == 1 &&  j != k){
                            count++;
                            flag = 0;
                            break;
                        }
                    }
                    if(flag == 1 )
{                    for(int k = 0 ; k < r ; k++){
                        if(grid[k][j] == 1 && i != k){
                            count++;
                            break;
                        }
                    }}
                }
            }
        }
        return count;
    }
};