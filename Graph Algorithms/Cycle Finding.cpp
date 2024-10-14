#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    ll n, m;
    cin >> n >> m;
 
    vector<pair<ll, ll>> adj[n + 1];
 
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
 
    vector<ll> dist(n + 1, INT_MAX);
    vector<ll> par(n + 1, -1);
 
    //dist[1] = 0; // Start from node 1
 
    // Bellman-Ford algorithm
    for (ll i = 0; i < n - 1; i++) {
        for (int j = 1; j <= n; j++) {
           // if (dist[j] == INT_MAX) continue;  // Skip unreachable nodes
            for (auto u : adj[j]) {
                ll nd_src = j;
                ll nd_dest = u.first;
                ll d = u.second;
 
                if (dist[nd_dest] > dist[nd_src] + d) {
                    dist[nd_dest] = dist[nd_src] + d;
                    par[nd_dest] = nd_src;
                }
            }
        }
    }
 
    pair<ll, ll> edge;
    bool isloop = false;
 
    // Check for negative cycles
    for (int j = 1; j <= n; j++) {
        //if (dist[j] == INT_MAX) continue;  // Skip unreachable nodes
        for (auto u : adj[j]) {
            ll nd_src = j;
            ll nd_dest = u.first;
            ll d = u.second;
 
            if (dist[nd_dest] > dist[nd_src] + d) {
                isloop = true;
                par[nd_dest] = nd_src;
                edge = {nd_src, nd_dest}; // We found a cycle involving this edge
                break;
            }
        }
        if (isloop) break; // Exit the loop if a cycle is found
    }
 
    cout << (isloop ? "YES\n" : "NO\n");
 
    if (!isloop) {
        return 0;
    }
 
    // To detect the negative cycle, trace back starting from the detected node
    vector<ll> result;
    ll cur = edge.second;
 
    // Reconstruct the cycle
    set<ll> visited_nodes;  // Use a set to detect repeated nodes
 
    // Traverse back until we encounter a repeated node
    while (visited_nodes.find(cur) == visited_nodes.end()) {
        visited_nodes.insert(cur);
        result.push_back(cur);
        cur = par[cur];
    }
 
    // Now, cur is part of the cycle, so reconstruct the cycle from cur
    vector<ll> cycle;
    cycle.push_back(cur);
    ll cycle_node = par[cur];
    while (cycle_node != cur) {
        cycle.push_back(cycle_node);
        cycle_node = par[cycle_node];
    }
    cycle.push_back(cur); // Close the cycle
 
    reverse(cycle.begin(), cycle.end()); // Reverse to get the correct order
 
    for (ll i = 0; i < cycle.size(); i++) {
        cout << cycle[i] << " ";
    }
    cout << endl;
 
    return 0;
}
