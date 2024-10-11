class Solution {
public:
    vector<int> shortestPath(vector<vector<pair<int,int>>> & adj,int V,int S){
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        vector<int> dist( V + 1, INT_MAX);
        dist[S] = 0;
        pq.push({0, S});

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto & i : adj[node]){
                int w = i.second;
                int edge = i.first;

                if(dis + w < dist[edge]){
                    dist[edge] = dis + w;
                    pq.push({dist[edge],edge});
                }
            }
        }
        dist[S] = 0;
        for(int & i : dist){
            if(i == INT_MAX){
                i = -1;
            }
        }
        return dist;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(
            n + 1);

        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];


            adj[u].push_back({v, w}); 

        }
        vector<int> path = shortestPath(adj,n,k);
        int res = -1;
        for(int i =  1; i <= n ; i++){
            if(path[i] == -1){
                return -1;
            }
            res = max(res , path[i]);
        }
        return res;
    }
};