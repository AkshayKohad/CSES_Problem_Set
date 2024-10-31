#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	int n;
	cin>>n;

	vector<int>nums(n);
	for(int i=0;i<n;i++)cin>>nums[i];

	sort(nums.begin(),nums.end());


	int result;

	if(n%2){
		result = nums[n/2];
	}else{
		result = (nums[n/2] + nums[n/2-1])/2;
	}

	ll answer = 0;

	for(ll i=0;i<n;i++)answer += abs(result-nums[i]);

	cout<<answer<<"\n";
}
