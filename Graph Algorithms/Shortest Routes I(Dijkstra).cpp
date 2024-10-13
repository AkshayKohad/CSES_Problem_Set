#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF LLONG_MAX

#define boost ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(){
    ll n,m;
    cin>>n>>m;
    
    vector<pair<ll,ll>>adj[n+1];
    
    for(ll i=0;i<m;i++){
        ll x,y,d;
        cin>>x>>y>>d;
        
        adj[x].push_back({y,d});
    }
    
    vector<ll>dist(n+1,INF);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    
    dist[1]=0;
    pq.push({0,1});
    
    while(pq.size()>0){
        pair<ll,ll>cur = pq.top();
        pq.pop();
        ll nd = cur.second;
        ll distance = cur.first;
        
        if(distance > dist[nd])continue;
        
        for(auto u:adj[nd]){
            ll cur_nd = u.first;
            ll d = u.second;
            if(dist[cur_nd] > dist[nd]+d){
                dist[cur_nd]=dist[nd]+d;
                pq.push({dist[cur_nd],cur_nd});
            }
        }
        
    }
    
    for(ll i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<"\n";
}
