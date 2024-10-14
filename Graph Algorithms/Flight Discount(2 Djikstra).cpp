#include <bits/stdc++.h>
using namespace std;

#define ll long long

void djisktra(ll src,vector<pair<ll,ll>>adj[],vector<ll>&dist){
    
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,src});
    dist[src]=0;
    
    while(pq.size()>0){
       pair<ll,ll>cur = pq.top();
       pq.pop();
       
       ll distance = cur.first;
       ll nd = cur.second;
       
       if(dist[nd]<distance)continue;
       
       for(auto u:adj[nd]){
           ll neigh_nd = u.first;
           ll d = u.second;
           
           if(dist[neigh_nd] > dist[nd]+d){
               dist[neigh_nd] = dist[nd]+d;
               pq.push({dist[neigh_nd],neigh_nd});
           }
       }
    }
}

int main(){
    ll n,m;
    cin>>n>>m;
    
    vector<pair<ll,ll>>adj[n+1];
    vector<pair<ll,ll>>adj_rev[n+1];
    
    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj_rev[b].push_back({a,c});
    }
    vector<ll>dist_source(n+1,LLONG_MAX);
    djisktra(1,adj,dist_source);
    
    vector<ll>dist_destination(n+1,LLONG_MAX);
    djisktra(n,adj_rev,dist_destination);
    
    ll result = LLONG_MAX;
    for(ll i=1;i<=n;i++){
        for(auto u:adj[i]){
            if(dist_source[i]==LLONG_MAX || dist_destination[u.first]==LLONG_MAX) continue;
            
            ll distance = dist_source[i] + (u.second/2) + dist_destination[u.first];
            result = min(result,distance);
        }
    }
    
    cout<<result<<"\n";
    
}
