#include <bits/stdc++.h>
using namespace std;

#define boost ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(){
	int n,m;
	cin>>n>>m;
	multiset<int>ticket_price;
	for(int i=0;i<n;i++){
		int val;
		cin>>val;
		ticket_price.insert(val);
	}

	for(int i=0;i<m;i++){
		int customer_price_limit;
		cin>>customer_price_limit;
		auto it = ticket_price.lower_bound(customer_price_limit);
		int cur_price = *it;
		if(cur_price == customer_price_limit){
			cout<<cur_price<<"\n";
			ticket_price.erase(it);
			continue;
		}
		
		if(it == ticket_price.begin()){
			cout<<"-1\n";
			continue;
		}
		
		it = prev(it);
		if(*it <= customer_price_limit){
			cout<<*it<<"\n";
			ticket_price.erase(it);
		}
	}
}
