#include <bits/stdc++.h>
using namespace std;

#define boost ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 1000000007
#define ll long long


int main(){
	ll n,m;
	cin>>n>>m;

	vector<pair<ll,ll>>adj[n+1];
	
	for(ll i=0;i<m;i++){
		ll src_nd,dest_nd,cost;
		cin>>src_nd>>dest_nd>>cost;

		adj[src_nd].push_back({dest_nd,cost});
	}

	
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

	pq.push({0,1});
	
	vector<ll>dist(n+1,LLONG_MAX);
	vector<ll>route(n+1,0);
	vector<ll>max_flights(n+1);
    vector<ll>min_flights(n+1);

	dist[1]=0;
	route[1]=1;
	
       	while(pq.size()>0){
		pair<ll,ll>cur = pq.top();
		pq.pop();
		ll distance = cur.first;
		ll nd = cur.second;

		if(distance > dist[nd]) continue;
		
		for(auto u:adj[nd]){
			ll neigh_nd = u.first;
			ll neigh_dist = u.second;

			if(dist[neigh_nd] == dist[nd] + neigh_dist){
				route[neigh_nd] += route[nd];
				route[neigh_nd] %= mod;
				
				min_flights[neigh_nd] = min(min_flights[neigh_nd],min_flights[nd]+1);
				max_flights[neigh_nd] = max(max_flights[neigh_nd],max_flights[nd]+1);
	
			} else if(dist[neigh_nd] > dist[nd] + neigh_dist){
				dist[neigh_nd] = dist[nd] + neigh_dist;
				route[neigh_nd] = route[nd];
				min_flights[neigh_nd] = min_flights[nd]+1;
				max_flights[neigh_nd] = max_flights[nd]+1;
				pq.push({dist[neigh_nd],neigh_nd});
			}
	
		} 
	}

	cout<<dist[n]<<" "<<route[n]<<" "<<min_flights[n]<<" "<<max_flights[n]<<"\n";

	return 0;
}
