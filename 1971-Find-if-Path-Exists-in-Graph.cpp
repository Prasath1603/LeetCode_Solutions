class Solution {
public:
    vector<int> parent;
    vector<int> size;

    void set(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void Uf(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return;

        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        set(n);
        for (auto& i : edges) {
            Uf(i[0], i[1]);
        }
        return find(source)==find(destination);
    }
};