#include <bits/stdc++.h>
using namespace std;
 
bool mycmp(pair<int,int>f,pair<int,int>s){
	if(f.second == s.second){
		return f.first < s.first;
	}
 
	return f.second < s.second; 
}
 
int main(){
	int n;
	cin>>n;
 
	vector<pair<int,int>>movie_time(n);
 
	for(int i=0;i<n;i++){
		int start,end;
		cin>>start>>end;
 
		movie_time[i] = {start,end};
	}
 
	sort(movie_time.begin(),movie_time.end(),mycmp);
	
	int res_movies = 0;
	int cnt_movies = 0;
 
	int end_time = -1;
 
 	for(int i=0;i<n;i++){
		if(end_time <= movie_time[i].first){
			end_time = movie_time[i].second;
			cnt_movies++;
		}
 
		res_movies = max(cnt_movies,res_movies);
	}
 
	cout<<res_movies<<"\n";
}
