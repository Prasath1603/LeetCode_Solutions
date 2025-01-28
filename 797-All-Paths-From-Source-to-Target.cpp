class Solution {
public:
    void dfs(vector<vector<int>>& adj , vector<int> &ans , vector<vector<int>>& res , int node , int target , vector<bool>&visited){
        if(node == target) res.push_back(ans);
        visited[node] = 1;

        for(auto & i : adj[node]){
            if(!visited[i]){
                ans.push_back(i);
                dfs(adj , ans , res , i , target,visited);
                ans.pop_back();
            }
        }

        visited[node] = 0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int m = graph.size();
        vector<vector<int>> res;
        vector<int> ans;
        ans.push_back(0);
        vector<bool> visited( m , 0);
        dfs(graph , ans , res , 0 , m - 1, visited);
        return res;
    }
};