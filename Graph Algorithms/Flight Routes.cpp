#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define boost ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
int main(){
    boost
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<pair<int, ll>> adj[n+1];
    for (ll i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    priority_queue<ll> dist[n + 1];
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    dist[1].push(0);
    
    while (!pq.empty()) {
        pair<ll, int> cur = pq.top();
        pq.pop();
        
        ll distance = cur.first;
        int nd = cur.second;
        
        if (dist[nd].size() == k && dist[nd].top() < distance) continue;
        
        for (auto u : adj[nd]) {
            int neigh_nd = u.first;
            ll d = u.second;
            ll new_distance = distance + d;
            
            
            if (dist[neigh_nd].size() == k) {
                if (dist[neigh_nd].top() > new_distance) {
                    dist[neigh_nd].pop();
                    dist[neigh_nd].push(new_distance);
                    pq.push({new_distance, neigh_nd});
                }
            } else {
                dist[neigh_nd].push(new_distance);
                pq.push({new_distance, neigh_nd});
            }
        }
    }
 
    vector<ll> result;
    while (dist[n].size() > 0) {
        result.push_back(dist[n].top());
        dist[n].pop();
    }
    
    
    reverse(result.begin(), result.end());
    
    for (ll i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}
