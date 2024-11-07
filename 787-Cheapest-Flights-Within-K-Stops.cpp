class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

       
        vector<pair<int,int>> graph[n];
        for (auto f : flights) {
            graph[f[0]].push_back({f[1], f[2]});  
        }

    
        queue<pair<int, pair<int,int>>> q;
        vector<int> dist(n, INT_MAX);  

        dist[src] = 0;
        q.push({0, {src, 0}});  

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            int stops = p.first;
            int node = p.second.first;
            int cost = p.second.second;

            if (stops <= k) {
             
                for (auto x : graph[node]) {
                    int next_node = x.first;
                    int edge_cost = x.second;

              
                    if (cost + edge_cost < dist[next_node]) {
                        dist[next_node] = cost + edge_cost;
                        q.push({stops + 1, {next_node, dist[next_node]}}); 
                    }
                }
            }
        }

      
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};
