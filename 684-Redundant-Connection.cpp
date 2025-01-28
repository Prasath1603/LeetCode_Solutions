class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    void _set(int n){
        parent.resize(n);
        rank.resize(n , 1);
        for(int i = 0 ; i < n ; i++) parent[i] = i;
    }
    int find(int u) {  
        if (u != parent[u]) {  
           return parent[u] = find(parent[u]); 
        }  
        return u;  
    }  
    void Union(int u , int v){
        int up = find(u);
        int vp = find(v);
        if(up == vp) return;
        if(rank[up] < rank[vp]){
            parent[up] = vp;
            rank[vp] += rank[up];
        }
        else{
            parent[vp] = up;
            rank[up] += rank[vp];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int v = edges.size() + 1;
        _set(v);
        vector<vector<int>> adj(v);
        for(auto & i : edges){
            if(find(i[0]) != find(i[1])){
                Union(i[0] , i[1]);
            }
            else{
                return i;
            }
        }
        return {};
    }
};