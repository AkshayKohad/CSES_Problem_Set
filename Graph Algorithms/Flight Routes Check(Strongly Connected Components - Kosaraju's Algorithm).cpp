#include <bits/stdc++.h>
using namespace std;

#define boost ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

void dfs(int src,vector<int>adj[],vector<int>&visited){
	visited[src] = 1;
	
	for(auto neigh_nd:adj[src]){
		if(visited[neigh_nd] == 0){
			dfs(neigh_nd,adj,visited);
		}
	}

	return;

}

int main(){
	boost
	int n,m;
	cin>>n>>m;

	vector<int>adj[n+1];
	vector<int>adj_rev[n+1];

	for(int i=0;i<m;i++){
		int src,dest;
		cin>>src>>dest;

		adj[src].push_back(dest);
		adj_rev[dest].push_back(src);
	} 

	vector<int>visited(n+1,0);
	vector<int>visited_rev(n+1,0);

	dfs(1,adj,visited);
	
	int node1,node2;
  	bool isPossible = true;

	for(int i=1;i<=n;i++){
		if(visited[i]!=1){
			isPossible = false;
			node1 = 1;
			node2 = i;
			break;	
		}
	}

	if(!isPossible){
		cout<<"NO\n";
		cout<<node1<<" "<<node2<<"\n";
		return 0;
	}

	dfs(1,adj_rev,visited_rev);

	for(int i=1;i<=n;i++){
		if(visited_rev[i]!=1){
			isPossible = false;
			node1 = i;
			node2 = 1;
			break;	
		}
	}

	
	if(!isPossible){
		cout<<"NO\n";
		cout<<node1<<" "<<node2<<"\n";
		return 0;
	}

	cout<<"YES\n";
	return 0;

		
}
