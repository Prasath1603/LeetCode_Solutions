#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> size;
    unordered_set<int> restrictedSet;


    void set(int n, vector<int>& restricted) {
        parent.resize(n);
        size.resize(n, 1);
        restrictedSet = unordered_set<int>(restricted.begin(), restricted.end());

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void Uf(int u, int v) {
        u = findP(u);
        v = findP(v);


        if (restrictedSet.count(u) || restrictedSet.count(v)) {
            return;
        }

        if (u == v) return;


        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }


    int findP(int u) {
        if (parent[u] != u) {
            parent[u] = findP(parent[u]);
        }
        return parent[u];
    }


    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        set(n, restricted);


        for (auto& edge : edges) {
            Uf(edge[0], edge[1]);
        }


        int rootOfZero = findP(0); 
        int reachableCount = 0;

        for (int i = 0; i < n; i++) {
            if (findP(i) == rootOfZero && restrictedSet.count(i) == 0) {
                reachableCount++;
            }
        }

        return reachableCount;
    }
};
