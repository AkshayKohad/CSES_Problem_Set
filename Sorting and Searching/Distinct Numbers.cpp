#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
	cin>>n;
 
	vector<int>a(n);
 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}	
 
	sort(a.begin(),a.end());
 
	int i=0;
	int cnt_distinct = 0;
 
	while(i<n){
		int j=i;
		
		while(j<n && a[i]==a[j]){
			j++;
		}
		cnt_distinct++;
		i=j;
	}
 
	cout<<cnt_distinct<<"\n";
}
