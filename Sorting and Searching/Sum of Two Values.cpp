#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n,x;
	cin>>n>>x;
 
	vector<pair<int,int>>nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i].first;
		nums[i].second = i+1;
	}
	
	sort(nums.begin(),nums.end());
	int i=0;
	int j=n-1;
	bool is_possible = false;
	while(i<j){
		int sum = nums[i].first + nums[j].first;
 
		if(sum>x){
			j--;
		}else if(sum<x){
			i++;
		}else{
			is_possible = true;
			cout<<min(nums[i].second,nums[j].second)<<" "<<max(nums[i].second,nums[j].second)<<"\n";
			break;
		}
	}
 
	if(!is_possible)cout<<"IMPOSSIBLE\n";
	
}
