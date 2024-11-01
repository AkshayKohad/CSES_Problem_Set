#include <bits/stdc++.h>
using namespace std;

#define boost ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
	boost;
	int x,n;

	cin>>x>>n;
	
	set<int>positions;
	multiset<int>distances;
	
	positions.insert(0);
	positions.insert(x);
	
	distances.insert(x);

	while(n--){
		int pos;
		cin>>pos;

		auto it = positions.lower_bound(pos);
		it--;
		auto prev = it;
		auto next = positions.upper_bound(pos);

		int diff = *next - *prev;
		
		auto cur = distances.lower_bound(diff);

		distances.erase(cur);

		distances.insert(pos-*prev);
		distances.insert(*next-pos);

		positions.insert(pos);

		cout<<*distances.rbegin()<<" ";
	}

	return 0;
}
