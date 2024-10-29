#include <bits/stdc++.h>
using namespace std;

int main(){

	int n,x;
	cin>>n>>x;

	vector<int>weight(n);
	vector<int>status(n,0);
	multiset<int>st;

	for(int i=0;i<n;i++){
		cin>>weight[i];
		st.insert(weight[i]);
	}

	int result = 0;
	int cnt_children = 0;

	while(cnt_children<n){
		
		result++;
		auto it = st.begin();
	
		st.erase(it);
		cnt_children++;
		//cout<<*it<<" "<<cnt_children<<"\n";
		if(cnt_children==n)break;

		int remaining = x - *it;

		auto itr = st.lower_bound(remaining);
		
		if(itr == st.end()){
			auto temp = prev(st.end());
			st.erase(temp);
			cnt_children++;
		}else if(itr == st.begin()){
			int val = *itr;
			if(val == remaining){
				auto temp = st.begin();
			        st.erase(temp);
			        cnt_children++;
			}			
		}else{
			int val = *itr;
			
			if(val == remaining){
			        st.erase(itr);
			        cnt_children++;
			}else{
				itr--;
				st.erase(itr);
			        cnt_children++;
			}
		}

	}

	cout<<result<<"\n";

	

	
}
