#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define boost ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll parent(ll nd,vector<ll>&par){
	if(par[nd]==-1)return nd;
 	
	return par[nd] = parent(par[nd],par);
}

void unite(ll nd1, ll nd2, vector<ll>&par, vector<ll>&rank){
	int par1 = parent(nd1,par);
	int par2 = parent(nd2,par);

	if(rank[par1]>=rank[par2]){
		rank[par1] += rank[par2];
		par[par2] = par1;
	}else{
	        rank[par2] += rank[par1];
		par[par1] = par2;
	}
}

int main(){
	ll n,m;
	cin>>n>>m;

	ll num_components = n;
	
	vector<ll>par(n+1,-1);
	vector<ll>rank(n+1,1);
	
	priority_queue<ll>largest_component;

	for(ll i=0;i<m;i++){
		ll city1,city2;
		cin>>city1>>city2;
		
		if(parent(city1,par) != parent(city2,par)){
			unite(city1,city2,par,rank);
			
			num_components--;
                        
                        ll cur_par = parent(city1,par);
			largest_component.push(rank[cur_par]);
		}

		cout<<num_components<<" "<<largest_component.top()<<"\n";
	}

	
}
