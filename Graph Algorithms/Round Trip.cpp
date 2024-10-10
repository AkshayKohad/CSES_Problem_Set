#include <bits/stdc++.h>
using namespace std;

bool is_cycle(int src, int par, vector<int>& visited, vector<int> adj[], int& dest, vector<int>& parent) {
    visited[src] = 1;
    parent[src] = par;

    for (auto u : adj[src]) {
        if (par == u) continue;

        if (visited[u] == 0) {
            bool res = is_cycle(u, src, visited, adj, dest, parent);
            if (res) return true;
        } else {
            // Set dest to the node that forms the back edge, not src
            dest = u;
            parent[u] = src;  // Track the back edge to reconstruct the cycle properly
            return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> visited(n + 1, 0);
    vector<int> parent(n + 1, -1);  // Initialize parent array to -1 for better debugging
    int source = -1;
    int dest = -1;
    bool res = false;
    
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            res = is_cycle(i, -1, visited, adj, dest, parent);

            if (res == true) {
                source = i;
                break;
            }
        }
    }

    if (!res) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> path;
    int cur = parent[dest];  // Start from the parent of the destination node
    path.push_back(dest);

    // Traverse back until we reach the destination again to complete the cycle
    while (cur != dest) {
        path.push_back(cur);
        cur = parent[cur];
    }

    path.push_back(dest);

    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << "\n";
}
