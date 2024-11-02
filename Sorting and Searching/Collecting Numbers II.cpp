#include <bits/stdc++.h>
using namespace std;


int main(){
	int n,m;
	cin>>n>>m;

	unordered_map<int,int>mp;

	vector<int>position(n+1);
	for(int i=0;i<n;i++){
		int val;
		cin>>val;

		position[val] = i+1;
		mp[i+1] = val;
	}

	int cnt_rounds = 1;
	int cur_position = -1;

	
	for(int i=1;i<=n;i++){
		if(cur_position > position[i]){
			cnt_rounds++;
		}
		cur_position = position[i];
	}


	while(m--){
		int a,b;
		cin>>a>>b;

		set<pair<int,int>>st;
		
		int val_a = mp[a];
		int val_b = mp[b];

		int cnt_inv_before_swap = 0;

		if(val_a-1>0)st.insert({val_a-1,val_a});

		if(val_b-1>0)st.insert({val_b-1,val_b});

		if(val_a+1<=n)st.insert({val_a,val_a+1});

		if(val_b+1<=n)st.insert({val_b,val_b+1});
		
		for(auto k:st){
			int val_first = position[k.first];
			int val_second = position[k.second];

			if(val_first>val_second)cnt_inv_before_swap++;
		}

		mp[a] = val_b;
		mp[b] = val_a;
		
		position[val_a] = b;
		position[val_b] = a;
		
		int cnt_inv_after_swap = 0;

		for(auto k:st){
			int val_first = position[k.first];
			int val_second = position[k.second];

			if(val_first>val_second)cnt_inv_after_swap++;
		}
		//cout<<a<<" "<<b<<endl;
		//cout<<cnt_inv_after_swap<<" "<<cnt_inv_before_swap<<endl;
		int result = cnt_rounds - cnt_inv_before_swap + cnt_inv_after_swap;
		cout<<result<<"\n";

		cnt_rounds = result;
		
	}

}
