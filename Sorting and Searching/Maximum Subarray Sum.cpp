#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ll n;	
	cin>>n;

	vector<ll>nums(n);
	ll res = LLONG_MIN;

	for(ll i=0;i<n;i++){
		cin>>nums[i];
		res = max(res,nums[i]);
	}

	if(res<=0){
		cout<<res<<"\n";
		return 0;
	}

	ll cur_sum = 0;
	for(ll i=0;i<n;i++){
		cur_sum += nums[i];

		if(cur_sum<0)cur_sum=0;

		res = max(res,cur_sum);
	}

	cout<<res<<"\n";
		
}
