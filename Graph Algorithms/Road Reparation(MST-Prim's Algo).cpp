#include <bits/stdc++.h>
using namespace std;

#define boost ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

int main(){
	ll n,m;
	cin>>n>>m;

	vector<pair<ll,ll>>adj[n+1];
	
	for(int i=0;i<m;i++){
		int src,dest,cost;
		cin>>src>>dest>>cost;
		adj[src].push_back({dest,cost});
		adj[dest].push_back({src,cost});
	}	

	vector<int>visited(n+1,0);
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

	pq.push({0,1});
	
	ll minimum_cost = 0;
	
	while(pq.size()>0){
		pair<ll,ll>cur = pq.top();
		pq.pop();
	
		ll distance = cur.first;
		ll nd = cur.second;
        
        if(visited[nd]==1)continue;
        
		visited[nd] = 1;
		minimum_cost += distance;
		
		
		for(auto u:adj[nd]){
			ll neigh_nd = u.first;
			ll neigh_cost = u.second;
	
			if(visited[neigh_nd]==1) continue;
						
			pq.push({neigh_cost,neigh_nd});
		}	
	}
    bool isPossible=true;
    for(ll i=1;i<=n;i++){
        if(visited[i]==0){
            isPossible=false;
        }
    }
    if(!isPossible){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
	cout<<minimum_cost<<"\n";
}
