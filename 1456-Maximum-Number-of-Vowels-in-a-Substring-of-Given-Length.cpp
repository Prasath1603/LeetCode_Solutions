#include <iostream>
#include <vector>
#include <limits>

class Solution {
public:
    int floyd(vector<vector<int>>& g, int n, int t) {
        vector<vector<int>> dist(n, vector<int>(n));
        int i, j, k;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i == j) {
                    dist[i][j] = 0;
                } else if (g[i][j] != 0) {
                    dist[i][j] = g[i][j];
                } else {
                    dist[i][j] = numeric_limits<int>::max() / 2;
                }
            }
        }
        for (k = 0; k < n; k++) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][j] == numeric_limits<int>::max() / 2) {
                    cout << \INF \;
                } else {
                    cout << dist[i][j] << \ \;
                }
            }
            cout << endl;
        }
        int r = 0, min = numeric_limits<int>::max();
        for (i = 0; i < n; i++) {
            int cnt = 0;
            for (j = 0; j < n; j++) {
                if (dist[i][j] <= t && dist[i][j] != 0) {
                    cnt++;
                }
            }
            if (cnt <= min) {
                min = cnt;
                r = i;
            }
        }
        return r;
    }

    int findTheCity(int n, vector<vector<int>>& graph, int t) {
        int i, j;
        vector<vector<int>> g(n, vector<int>(n));
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i != j) {
                    g[i][j] = numeric_limits<int>::max() / 2;
                } else {
                    g[i][j] = 0;
                }
            }
        }
        for (const auto& edge : graph) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            g[u][v] = weight;
            g[v][u] = weight;
        }
        return floyd(g, n, t);
    }
};

