#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;

	vector<int>position(n+1);
	for(int i=0;i<n;i++){
		int val;
		cin>>val;
	
		position[val]=i;
	}

	int cnt_rounds = 1;
	int cur_position = -1;

	for(int i=1;i<=n;i++){
		if(cur_position > position[i]){
			cnt_rounds++;
		}

		cur_position = position[i];
	}

	cout<<cnt_rounds<<"\n";
	return 0;
}
