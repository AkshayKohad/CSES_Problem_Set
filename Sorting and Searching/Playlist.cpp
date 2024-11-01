#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>songs(n);
	for(int i=0;i<n;i++)cin>>songs[i];
	set<int>st;
	int i=0;
	int j=0;
	int result = 0;
	while(j<n){
		if(st.find(songs[j]) != st.end()){
			int song = songs[j];
			while(i<j && songs[i]!=song){
				st.erase(songs[i]);
				i++;
			}
			st.erase(songs[i]);
			i++;
		}	
    st.insert(songs[j]);
		j++;
		result = max(result,j-i);
	}
	cout<<result<<"\n";
}
