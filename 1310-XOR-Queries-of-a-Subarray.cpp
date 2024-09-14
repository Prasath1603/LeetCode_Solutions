class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> v;
        int i, n = arr.size(), j;
        for (i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            if (start == end) {
                v.push_back(arr[start]);
                continue;
            } else {
                int res = arr[start];
                for(j=start+1;j<=end;j++){
                    res = (res^arr[j]);
                }
                v.push_back(res);
            }
        }
        return v;
    }
};