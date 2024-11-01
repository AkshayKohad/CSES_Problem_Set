#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
	cin>>n;
	
	multiset<int>st;
 
	for(int i=0;i<n;i++){
		int val;
		cin>>val;
 
		if(st.empty()){
			st.insert(val);
			continue;
		}
		auto it = st.upper_bound(val);
		if(it == st.end()){
			st.insert(val);
			continue;
		}
		st.erase(it);
		st.insert(val);
	}
	cout<<st.size()<<"\n";
	
}
