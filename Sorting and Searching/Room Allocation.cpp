#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
	cin>>n;
	vector<int>result(n);
	vector<vector<int>>customers(n);
	for(int i=0;i<n;i++){
		int arrival,departure;
		cin>>arrival>>departure;
		customers[i] = {arrival,departure,i};
	}
	sort(customers.begin(),customers.end());
	priority_queue<int,vector<int>,greater<int>>available_rooms;
	for(int i=1;i<=n;i++)available_rooms.push(i);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>occupied_room;
	int cur_departure = -1;
	int prev_room = -1;
	int max_rooms_utilized = 0;
	for(int i=0;i<n;i++){
		vector<int>cur = customers[i];
		int cur_arrival = cur[0];
		while(!occupied_room.empty() && occupied_room.top().first < cur_arrival){
			pair<int,int>queue_cur = occupied_room.top();
			occupied_room.pop();
			available_rooms.push(queue_cur.second);
		}	
		prev_room = available_rooms.top();
		available_rooms.pop();
		result[cur[2]] = prev_room;
		max_rooms_utilized = max(max_rooms_utilized,prev_room);
		occupied_room.push({cur[1],result[cur[2]]});
	}
	cout<<max_rooms_utilized<<"\n";
	for(int i=0;i<n;i++)cout<<result[i]<<" ";
	cout<<"\n";
}
