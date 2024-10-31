#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	vector<int>nums(n);

	for(int i=0;i<n;i++)cin>>nums[i];
	
	sort(nums.begin(),nums.end());

	long long sum = 0;
	

	for(int i=0;i<n;i++){
		if(sum>=nums[i]){
			sum += nums[i];
			continue;
		}

		if(nums[i]-sum<=1){
			sum += nums[i];
			continue;
		}
		
		break;
				
	}

		cout<<sum+1<<"\n";

}
