#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>required_apartments(n);
 
	for(int i=0;i<n;i++)cin>>required_apartments[i];
	
	vector<int>apartments(m);
 
	for(int i=0;i<m;i++)cin>>apartments[i];
	
	sort(required_apartments.begin(),required_apartments.end());
 
	sort(apartments.begin(),apartments.end());
 
	int i=0;
	int j=0;
	int cnt_residents = 0;
 
	while(i<n && j<m){
		if(required_apartments[i]+k < apartments[j]){
		    i++;
		    continue;
		}
		else if(required_apartments[i]-k > apartments[j]){
		    j++;
		    continue;
        }
		i++;
		j++;
		cnt_residents++;
	}
 
	cout<<cnt_residents<<"\n";
}
