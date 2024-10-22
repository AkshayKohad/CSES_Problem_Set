#include <bits/stdc++.h>
using namespace std;

#define boost ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void dfs(int src,vector<int>adj[],vector<int>&visited,stack<int>&st){
	visited[src] = 1;
	for(auto u:adj[src]){
 		if(visited[u]==1)continue;
		dfs(u,adj,visited,st);
  	}
	
	st.push(src);
	return;
}

void dfs_rev(int src,vector<int>adj[],vector<int>&visited,int &scc_id){
	visited[src] = scc_id;
	for(auto u:adj[src]){
 		if(visited[u]!=0)continue;
		dfs_rev(u,adj,visited,scc_id);
  	}
	
	return;
}

int main(){
	int n,m;
	cin>>n>>m;

	vector<int>adj[n+1];
	vector<int>adj_rev[n+1];
	for(int i=0;i<m;i++){
		int src_nd,dest_nd;
		cin>>src_nd>>dest_nd;
		adj[src_nd].push_back(dest_nd);
		adj_rev[dest_nd].push_back(src_nd);
	}

	// Kosaraju's Algorithms

	// Step 1 - Ordering of nodes pushing elements in order of sink to source
	stack<int>st;
    vector<int>visited(n+1,0);
	for(int i=1;i<=n;i++){
		if(visited[i] == 1)continue;

		dfs(i,adj,visited,st);
	}

	vector<int>visited_rev(n+1,0);
	int cnt_scc = 0;

	while(st.empty() == false){
       		int nd = st.top();
		st.pop();
		
		if(visited_rev[nd]!=0) continue;
		cnt_scc++;
		dfs_rev(nd,adj_rev,visited_rev,cnt_scc);
	}

	cout<<cnt_scc<<"\n";

	for(int i=1;i<=n;i++){
		cout<<visited_rev[i]<<" ";
	}
	cout<<"\n";
}
