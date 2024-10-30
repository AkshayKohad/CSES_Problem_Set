#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ll n;
	cin>>n;

	map<ll,ll>mp;

	for(ll i=0;i<n;i++){
		ll start,end;
		cin>>start>>end;
		
		mp[start] += 1;
		mp[end] -= 1;
	}

	ll result = 0;
	ll pref = 0;
	for(auto k:mp){
		pref += k.second;
		
		result = max(result,pref);
	}

	cout<<result<<"\n";
}
